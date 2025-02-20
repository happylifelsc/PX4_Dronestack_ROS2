// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from offboard_ros2:msg/CombinedData.idl
// generated code does not contain a copyright notice

#ifndef OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__BUILDER_HPP_
#define OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "offboard_ros2/msg/detail/combined_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace offboard_ros2
{

namespace msg
{

namespace builder
{

class Init_CombinedData_vicon_posi_z
{
public:
  explicit Init_CombinedData_vicon_posi_z(::offboard_ros2::msg::CombinedData & msg)
  : msg_(msg)
  {}
  ::offboard_ros2::msg::CombinedData vicon_posi_z(::offboard_ros2::msg::CombinedData::_vicon_posi_z_type arg)
  {
    msg_.vicon_posi_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::offboard_ros2::msg::CombinedData msg_;
};

class Init_CombinedData_vicon_posi_y
{
public:
  explicit Init_CombinedData_vicon_posi_y(::offboard_ros2::msg::CombinedData & msg)
  : msg_(msg)
  {}
  Init_CombinedData_vicon_posi_z vicon_posi_y(::offboard_ros2::msg::CombinedData::_vicon_posi_y_type arg)
  {
    msg_.vicon_posi_y = std::move(arg);
    return Init_CombinedData_vicon_posi_z(msg_);
  }

private:
  ::offboard_ros2::msg::CombinedData msg_;
};

class Init_CombinedData_vicon_posi_x
{
public:
  explicit Init_CombinedData_vicon_posi_x(::offboard_ros2::msg::CombinedData & msg)
  : msg_(msg)
  {}
  Init_CombinedData_vicon_posi_y vicon_posi_x(::offboard_ros2::msg::CombinedData::_vicon_posi_x_type arg)
  {
    msg_.vicon_posi_x = std::move(arg);
    return Init_CombinedData_vicon_posi_y(msg_);
  }

private:
  ::offboard_ros2::msg::CombinedData msg_;
};

class Init_CombinedData_stair_pos_z
{
public:
  explicit Init_CombinedData_stair_pos_z(::offboard_ros2::msg::CombinedData & msg)
  : msg_(msg)
  {}
  Init_CombinedData_vicon_posi_x stair_pos_z(::offboard_ros2::msg::CombinedData::_stair_pos_z_type arg)
  {
    msg_.stair_pos_z = std::move(arg);
    return Init_CombinedData_vicon_posi_x(msg_);
  }

private:
  ::offboard_ros2::msg::CombinedData msg_;
};

class Init_CombinedData_header
{
public:
  Init_CombinedData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CombinedData_stair_pos_z header(::offboard_ros2::msg::CombinedData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CombinedData_stair_pos_z(msg_);
  }

private:
  ::offboard_ros2::msg::CombinedData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::offboard_ros2::msg::CombinedData>()
{
  return offboard_ros2::msg::builder::Init_CombinedData_header();
}

}  // namespace offboard_ros2

#endif  // OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__BUILDER_HPP_
