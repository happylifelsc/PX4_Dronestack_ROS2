// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from offboard_ros2:msg/CombinedData.idl
// generated code does not contain a copyright notice

#ifndef OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__TRAITS_HPP_
#define OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "offboard_ros2/msg/detail/combined_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace offboard_ros2
{

namespace msg
{

inline void to_flow_style_yaml(
  const CombinedData & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: stair_pos_z
  {
    out << "stair_pos_z: ";
    rosidl_generator_traits::value_to_yaml(msg.stair_pos_z, out);
    out << ", ";
  }

  // member: vicon_posi_x
  {
    out << "vicon_posi_x: ";
    rosidl_generator_traits::value_to_yaml(msg.vicon_posi_x, out);
    out << ", ";
  }

  // member: vicon_posi_y
  {
    out << "vicon_posi_y: ";
    rosidl_generator_traits::value_to_yaml(msg.vicon_posi_y, out);
    out << ", ";
  }

  // member: vicon_posi_z
  {
    out << "vicon_posi_z: ";
    rosidl_generator_traits::value_to_yaml(msg.vicon_posi_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CombinedData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: stair_pos_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stair_pos_z: ";
    rosidl_generator_traits::value_to_yaml(msg.stair_pos_z, out);
    out << "\n";
  }

  // member: vicon_posi_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vicon_posi_x: ";
    rosidl_generator_traits::value_to_yaml(msg.vicon_posi_x, out);
    out << "\n";
  }

  // member: vicon_posi_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vicon_posi_y: ";
    rosidl_generator_traits::value_to_yaml(msg.vicon_posi_y, out);
    out << "\n";
  }

  // member: vicon_posi_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vicon_posi_z: ";
    rosidl_generator_traits::value_to_yaml(msg.vicon_posi_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CombinedData & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace offboard_ros2

namespace rosidl_generator_traits
{

[[deprecated("use offboard_ros2::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const offboard_ros2::msg::CombinedData & msg,
  std::ostream & out, size_t indentation = 0)
{
  offboard_ros2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use offboard_ros2::msg::to_yaml() instead")]]
inline std::string to_yaml(const offboard_ros2::msg::CombinedData & msg)
{
  return offboard_ros2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<offboard_ros2::msg::CombinedData>()
{
  return "offboard_ros2::msg::CombinedData";
}

template<>
inline const char * name<offboard_ros2::msg::CombinedData>()
{
  return "offboard_ros2/msg/CombinedData";
}

template<>
struct has_fixed_size<offboard_ros2::msg::CombinedData>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<offboard_ros2::msg::CombinedData>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<offboard_ros2::msg::CombinedData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__TRAITS_HPP_
