#ifndef STAIR_CTRL_ROS2_H
#define STAIR_CTRL_ROS2_H

#include <chrono>
#include <functional>
#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <mavros_msgs/msg/distance_sensor.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <msg_interfaces/msg/combined_data.hpp>
#include <cstdint>

#include <deque>
#include <algorithm>


// Function declarations
void laserScan_cb(const sensor_msgs::msg::LaserScan::SharedPtr msg);
void distanceSensor_cb(const mavros_msgs::msg::DistanceSensor::SharedPtr msg);
void viconPose_cb(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
void xDirectionAjustment();
void stepCounting();
float medianFilter(std::deque<float>& window, float new_value);

// Global shared pointer for the ROS node
inline rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_scan_sub;
inline rclcpp::Subscription<mavros_msgs::msg::DistanceSensor>::SharedPtr distance_sensor_sub;
inline rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr vicon_pose_sub;
inline rclcpp::Publisher<msg_interfaces::msg::CombinedData>::SharedPtr combined_data_pub;
inline geometry_msgs::msg::PoseStamped vision_pose_msg;
inline msg_interfaces::msg::CombinedData combined_data_msg;;

inline float prev_height = 0.0;
inline float height_change = 0.0;
inline float height;

#endif // STAIR_CTRL_ROS2_H



