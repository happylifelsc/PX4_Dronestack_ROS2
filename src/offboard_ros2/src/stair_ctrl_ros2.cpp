#include "offboard_ros2/stair_ctrl_ros2.h"

std::shared_ptr<rclcpp::Node> node;

static float step_height = 26.0; // the unit is cm
static float step_x_length = 0.26; // the unit is m
static float step_x_error = 0.08;
static int num_steps = 0;
static float stair_posi_x = 0.0;
static float stair_posi_y = 0.0;
static float stair_posi_z = 0.0;
static float step_height_error = 8.0;
static int consecutive_points = 0;    // Tracks the number of consecutive points contributing to the change
static float cumulative_change = 0.0; // Tracks the cumulative height change
static float x_dist_to_stair = 0.0;
static float prev_x_dist_to_stair = 0.0;
static float delta_x_dist = 0.0;

std::deque<float> height_window;  // Sliding window for median filter
constexpr int MEDIAN_WINDOW_SIZE = 5;  // Adjust based on noise level

// Main function
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    // Initialize the node and subscription
    node = rclcpp::Node::make_shared("staircase_nav_node");

    // sensor_qos optimizes the communication by assuming only the latest data is important and there is no need to guarantee delivery
    auto sensor_qos = rclcpp::SensorDataQoS();

    // Create the subscription to the LaserScan topic
    laser_scan_sub = node->create_subscription<sensor_msgs::msg::LaserScan>(
        "/scan", sensor_qos, laserScan_cb);

    distance_sensor_sub = node->create_subscription<mavros_msgs::msg::DistanceSensor>(
        "/mavros/distance_sensor/current_distance", sensor_qos, distanceSensor_cb);

    vicon_pose_sub = node->create_subscription<geometry_msgs::msg::PoseStamped>(
        "/vrpn_mocap/x8_1/pose", sensor_qos, viconPose_cb);

    combined_data_pub = node->create_publisher<msg_interfaces::msg::CombinedData>(
        "combined_data", sensor_qos);


    RCLCPP_INFO(node->get_logger(), "Staircase Navigation Node Initialized");

    rclcpp::Rate rate(20.0);
    rclcpp::Clock clock;


    while (rclcpp::ok()) {

        stepCounting();
        xDirectionAjustment();

        stair_posi_z = (num_steps * step_height + height)/100;

        combined_data_msg.header.stamp = clock.now();
        combined_data_msg.height = height;
        combined_data_msg.stair_posi_x = stair_posi_x;
        combined_data_msg.stair_posi_y = stair_posi_y;
        combined_data_msg.stair_posi_z = stair_posi_z;
        combined_data_msg.vicon_posi_x = vision_pose_msg.pose.position.x;
        combined_data_msg.vicon_posi_y = vision_pose_msg.pose.position.y;
        combined_data_msg.vicon_posi_z = vision_pose_msg.pose.position.z;
        combined_data_msg.cumulative_change = cumulative_change;
        combined_data_msg.consecutive_points = consecutive_points;
        combined_data_msg.delta_x_dist = delta_x_dist;
        combined_data_msg.x_dist_to_stair = x_dist_to_stair;

        combined_data_pub->publish(combined_data_msg);

        
        rclcpp::spin_some(node->get_node_base_interface());
        rate.sleep();
    }

    return 0;

}


// Callback function for processing LaserScan messages
void laserScan_cb(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
    // Example: Print the first range value (if available)
    // if (!msg->ranges.empty()) {
    //     RCLCPP_INFO(node->get_logger(), "distance to the wall: %.2f", msg->ranges[900]);
    //     RCLCPP_INFO(node->get_logger(), "x distance to the stair: %.2f", msg->ranges[540]);
    // }
    // else {
    //     RCLCPP_WARN(node->get_logger(), "No range data available");
    // }

    x_dist_to_stair = msg->ranges[540];
    stair_posi_y = msg->ranges[900];
}


// Callback function for processing DistanceSensor messages
void distanceSensor_cb(const mavros_msgs::msg::DistanceSensor::SharedPtr msg) {
    uint16_t height_int = msg->current_distance;
    // RCLCPP_INFO(node->get_logger(), "current distance: %u", height_int);

    float raw_height = static_cast<float>(height_int);


    height = medianFilter(height_window, raw_height);
}


void viconPose_cb(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
{


    vision_pose_msg.header.frame_id = "map";
    vision_pose_msg.header.stamp = node->now();
    vision_pose_msg.pose.position.x = msg->pose.position.x;
    vision_pose_msg.pose.position.y = msg->pose.position.y;
    vision_pose_msg.pose.position.z = msg->pose.position.z;
    vision_pose_msg.pose.orientation.x = msg->pose.orientation.x;
    vision_pose_msg.pose.orientation.y = msg->pose.orientation.y;
    vision_pose_msg.pose.orientation.z = msg->pose.orientation.z;
    vision_pose_msg.pose.orientation.w = msg->pose.orientation.w;

    // RCLCPP_INFO(node->get_logger(), "Check vision_pose: x: %.2f, y: %.2f, z: %.2f", vision_pose_msg.pose.position.x, vision_pose_msg.pose.position.y, vision_pose_msg.pose.position.z);

    // px4_vision_pose_pub->publish(vision_pose_msg);
}


// void stepCounting() {
//     // Check for sudden height changes
//     if (std::abs(height - prev_height) >= step_height) {
//         if (height - prev_height > 0) {
//             // Sudden increase in height (step up)
//             num_steps++;
//             RCLCPP_INFO(node->get_logger(), "Step up detected. num_steps = %d", num_steps);
//         } else if (prev_height - height > 0) {
//             // Sudden decrease in height (step down)
//             num_steps--;
//             RCLCPP_INFO(node->get_logger(), "Step down detected. num_steps = %d", num_steps);
//         }
//     }


//     // Update the previous height for the next comparison
//     prev_height = height;


// }



// void stepCounting() {
//     // Check for sudden height changes
//     float height_change = height - prev_height;

//     if (std::abs(height_change) >= (step_height - step_error))) {
//         // Calculate the number of steps based on the height change
//         int step_delta = static_cast<int>(height_change / step_height);

//         // Update the total number of steps
//         num_steps += step_delta;

//         // Log the step change
//         if (step_delta > 0) {
//             RCLCPP_INFO(node->get_logger(), "Step up detected. num_steps = %d", num_steps);
//         } else if (step_delta < 0) {
//             RCLCPP_INFO(node->get_logger(), "Step down detected. num_steps = %d", num_steps);
//         }
//     }

//     // Update the previous height for the next comparison
//     prev_height = height;
// }




// void stepCounting() {
//     static float cumulative_change = 0.0; // Tracks the cumulative change between consecutive points

//     // Calculate the current height change
//     float height_change = height - prev_height;

//     // If the change is in the same direction as the previous change, accumulate it
//     if ((cumulative_change >= 0 && height_change >= 0) || (cumulative_change <= 0 && height_change <= 0)) {
//         cumulative_change += height_change;
//     } else {
//         // Reset cumulative change if direction changes
//         cumulative_change = height_change;
//     }

//     // Check if the cumulative change meets the threshold
//     if (std::abs(cumulative_change) >= (step_height - step_error)) {
//         if (cumulative_change > 0) {
//             // Sudden increase (step up)
//             num_steps++;
//             RCLCPP_INFO(node->get_logger(), "Step up detected. num_steps = %d", num_steps);
//         } else if (cumulative_change < 0) {
//             // Sudden decrease (step down)
//             num_steps--;
//             RCLCPP_INFO(node->get_logger(), "Step down detected. num_steps = %d", num_steps);
//         }

//         // Reset cumulative change after registering a step
//         cumulative_change = 0.0;
//     }

//     // Update the previous height
//     prev_height = height;
// }



// void stepCounting() {
//     static float cumulative_change = 0.0; // Tracks the cumulative height change
//     static int consecutive_points = 0;    // Tracks the number of consecutive points contributing to the change
//     const int max_sudden_points = 2;      // Define how many points can be considered a "sudden change"

//     // Calculate the current height change
//     float height_change = height - prev_height;

//     // Check if the change is in the same direction
//     if ((cumulative_change >= 0 && height_change >= 0) || (cumulative_change <= 0 && height_change <= 0)) {
//         // Accumulate the change and increment the consecutive point counter
//         cumulative_change += height_change;
//         consecutive_points++;
//     } else {
//         // Reset cumulative change and point counter if the direction changes
//         cumulative_change = height_change;
//         consecutive_points = 1;
//     }

//     // Check if the cumulative change meets the threshold and is within the sudden change limit
//     if (std::abs(cumulative_change) >= (step_height - step_error) && consecutive_points <= max_sudden_points) {
//         if (cumulative_change > 0) {
//             // Sudden increase (step up)
//             num_steps++;
//             RCLCPP_INFO(node->get_logger(), "Step up detected. num_steps = %d", num_steps);
//         } else if (cumulative_change < 0) {
//             // Sudden decrease (step down)
//             num_steps--;
//             RCLCPP_INFO(node->get_logger(), "Step down detected. num_steps = %d", num_steps);
//         }

//         // Reset cumulative change and point counter after registering a step
//         cumulative_change = 0.0;
//         consecutive_points = 0;
//     }

//     // If the consecutive points exceed the sudden change limit, treat it as a gradual change and reset
//     if (consecutive_points > max_sudden_points) {
//         cumulative_change = 0.0;
//         consecutive_points = 0;
//     }

//     // Update the previous height
//     prev_height = height;
// }



// you need to cumulatively add a delta change to stair_posi_x
void xDirectionAjustment() {
    // Calculate the current height change
    
    if(prev_x_dist_to_stair != 0.0) { // we directly pass x_dist_to_stair to prev_x_dist_to_stair in the first run
        delta_x_dist = prev_x_dist_to_stair - x_dist_to_stair;
    
        RCLCPP_INFO(node->get_logger(), "delta_x_dist: %.2f", delta_x_dist);
        

        // based on previous experiment when the drone is on the ground, we think the noise of lidar is around -0.03 to 0.03.
        // you need to hover the drone to find this cutoff one more time
        // choose -0.3 to filter platform (it needs to be smaller than -0.26), choose 0.5 to filter the high spike around 60 m.
        // we assume the length of a stair in x direction cannot be larger than 0.3m, if detected, we ignore this message.
        // we assume the speed is slower than 0.5m/between two runs (0.05s for 20hz)
        if(delta_x_dist > -0.3 && delta_x_dist < 0.5) { 
            // -(step_x_length - step_x_error) 
            if( delta_x_dist > -0.3 && delta_x_dist < -0.03) { // stair detected
                delta_x_dist = delta_x_dist + (step_x_length - step_x_error);
            }
        
            stair_posi_x += delta_x_dist;
        }
    }

    prev_x_dist_to_stair = x_dist_to_stair;

}


void stepCounting() {
    const int max_sudden_points = 20;      // Define how many points can be considered a "sudden change"

    // Calculate the current height change
    float height_change = height - prev_height;



    // Handle case 1: Drone moves too fast, resulting in a single large height change
    if (std::abs(height_change) >= (step_height - step_height_error)) {
        
        RCLCPP_INFO(node->get_logger(), "height: %f", height);
        RCLCPP_INFO(node->get_logger(), "prev_height: %f", prev_height);
        RCLCPP_INFO(node->get_logger(), "height_change: %f", height_change);
        
        // Calculate the number of steps based on the height change
        int step_delta = static_cast<int>(height_change / (step_height - step_height_error));


        // Log the step change
        if (step_delta < 0) {
            num_steps -= step_delta;
            RCLCPP_INFO(node->get_logger(), "Fast movement: Step up detected. num_steps = %d", num_steps);
        } 
        // else if (step_delta > 0) {
        //     num_steps -= step_delta;
        //     RCLCPP_INFO(node->get_logger(), "Fast movement: Step down detected. num_steps = %d", num_steps);
        // }
    }
    // Handle case 2: Drone moves gradually, and use max_sudden_points logic
    else {

        // Check if the change is in the same direction
        if ((cumulative_change >= 0 && height_change >= 0) || (cumulative_change <= 0 && height_change <= 0)) {
            // Accumulate the change and increment the consecutive point counter
            cumulative_change += height_change;
            consecutive_points++;
        } 
        else {
            // Reset cumulative change and point counter if the direction changes
            cumulative_change = height_change;
            consecutive_points = 1;
        }

        // Check if the cumulative change meets the threshold and is within the sudden change limit
        //  && consecutive_points <= max_sudden_points)
        if (std::abs(cumulative_change) >= (step_height - step_height_error) && consecutive_points <= max_sudden_points) {

            RCLCPP_INFO(node->get_logger(), "cumulative_change: %f", cumulative_change);

            if (cumulative_change < 0) {
                // Sudden increase (step up)
                num_steps++;
                RCLCPP_INFO(node->get_logger(), "Gradual movement: Step up detected. num_steps = %d", num_steps);
            } 
            // else if (cumulative_change > 0) {
            //     // Sudden decrease (step down)
            //     num_steps--;
            //     RCLCPP_INFO(node->get_logger(), "Gradual movement: Step down detected. num_steps = %d", num_steps);
            // }

            // Reset cumulative change and point counter after registering a step
            cumulative_change = 0.0;
            consecutive_points = 0;
        }

        // If the consecutive points exceed the sudden change limit, do not treat it as a step and reset
        if (consecutive_points > max_sudden_points) {
            cumulative_change = 0.0;
            consecutive_points = 0;
        }
    }

    // Update the previous height
    prev_height = height;
}


float medianFilter(std::deque<float>& window, float new_value) {
    window.push_back(new_value);
    if (window.size() > MEDIAN_WINDOW_SIZE) {
        window.pop_front();  // Maintain fixed window size
    }

    std::vector<float> sorted_window(window.begin(), window.end());
    std::sort(sorted_window.begin(), sorted_window.end());

    return sorted_window[sorted_window.size() / 2];  // Return median value
}
















