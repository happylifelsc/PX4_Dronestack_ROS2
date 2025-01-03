#ifndef STAIR_CTRL_ROS2_H
#define STAIR_CTRL_ROS2_H

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>

// Function declarations
void laserScanCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg);
void initializeRosNode();

// Global shared pointer for the ROS node
extern rclcpp::Node::SharedPtr node_;
extern rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_scan_sub_;

#endif // STAIR_CTRL_ROS2_H
