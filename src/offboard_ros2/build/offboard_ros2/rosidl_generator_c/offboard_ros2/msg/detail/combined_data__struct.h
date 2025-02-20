// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from offboard_ros2:msg/CombinedData.idl
// generated code does not contain a copyright notice

#ifndef OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__STRUCT_H_
#define OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/CombinedData in the package offboard_ros2.
typedef struct offboard_ros2__msg__CombinedData
{
  std_msgs__msg__Header header;
  float stair_pos_z;
  float vicon_posi_x;
  float vicon_posi_y;
  float vicon_posi_z;
} offboard_ros2__msg__CombinedData;

// Struct for a sequence of offboard_ros2__msg__CombinedData.
typedef struct offboard_ros2__msg__CombinedData__Sequence
{
  offboard_ros2__msg__CombinedData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} offboard_ros2__msg__CombinedData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__STRUCT_H_
