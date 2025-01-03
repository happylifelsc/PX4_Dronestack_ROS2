#include "offboard_ros2/stair_ctrl_ros2.h"

// Global variables
rclcpp::Node::SharedPtr node_;
rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_scan_sub_;

// Callback function for processing LaserScan messages
void laserScanCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
    RCLCPP_INFO(node_->get_logger(), "Received LaserScan message:");
    RCLCPP_INFO(node_->get_logger(), "Angle Min: %.2f, Angle Max: %.2f", msg->angle_min, msg->angle_max);
    RCLCPP_INFO(node_->get_logger(), "Range data size: %zu", msg->ranges.size());

    // Example: Print the first range value (if available)
    if (!msg->ranges.empty()) {
        RCLCPP_INFO(node_->get_logger(), "First range value: %.2f", msg->ranges[0]);
    } else {
        RCLCPP_WARN(node_->get_logger(), "No range data available");
    }
}

// Function to initialize the ROS node and subscription
void initializeRosNode() {
    node_ = rclcpp::Node::make_shared("staircase_nav_node");

    // Create the subscription to the LaserScan topic
    laser_scan_sub_ = node_->create_subscription<sensor_msgs::msg::LaserScan>(
        "/scan", 10, laserScanCallback);

    RCLCPP_INFO(node_->get_logger(), "Staircase Navigation Node Initialized");
}

// Main function
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    // Initialize the node and subscription
    initializeRosNode();

    // Keep spinning to process incoming messages
    rclcpp::spin(node_);

    rclcpp::shutdown();
    return 0;
}
