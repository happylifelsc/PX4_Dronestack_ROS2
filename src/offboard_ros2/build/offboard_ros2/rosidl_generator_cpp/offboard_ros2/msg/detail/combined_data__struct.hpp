// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from offboard_ros2:msg/CombinedData.idl
// generated code does not contain a copyright notice

#ifndef OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__STRUCT_HPP_
#define OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__offboard_ros2__msg__CombinedData __attribute__((deprecated))
#else
# define DEPRECATED__offboard_ros2__msg__CombinedData __declspec(deprecated)
#endif

namespace offboard_ros2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CombinedData_
{
  using Type = CombinedData_<ContainerAllocator>;

  explicit CombinedData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stair_pos_z = 0.0f;
      this->vicon_posi_x = 0.0f;
      this->vicon_posi_y = 0.0f;
      this->vicon_posi_z = 0.0f;
    }
  }

  explicit CombinedData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stair_pos_z = 0.0f;
      this->vicon_posi_x = 0.0f;
      this->vicon_posi_y = 0.0f;
      this->vicon_posi_z = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _stair_pos_z_type =
    float;
  _stair_pos_z_type stair_pos_z;
  using _vicon_posi_x_type =
    float;
  _vicon_posi_x_type vicon_posi_x;
  using _vicon_posi_y_type =
    float;
  _vicon_posi_y_type vicon_posi_y;
  using _vicon_posi_z_type =
    float;
  _vicon_posi_z_type vicon_posi_z;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__stair_pos_z(
    const float & _arg)
  {
    this->stair_pos_z = _arg;
    return *this;
  }
  Type & set__vicon_posi_x(
    const float & _arg)
  {
    this->vicon_posi_x = _arg;
    return *this;
  }
  Type & set__vicon_posi_y(
    const float & _arg)
  {
    this->vicon_posi_y = _arg;
    return *this;
  }
  Type & set__vicon_posi_z(
    const float & _arg)
  {
    this->vicon_posi_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    offboard_ros2::msg::CombinedData_<ContainerAllocator> *;
  using ConstRawPtr =
    const offboard_ros2::msg::CombinedData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<offboard_ros2::msg::CombinedData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<offboard_ros2::msg::CombinedData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      offboard_ros2::msg::CombinedData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<offboard_ros2::msg::CombinedData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      offboard_ros2::msg::CombinedData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<offboard_ros2::msg::CombinedData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<offboard_ros2::msg::CombinedData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<offboard_ros2::msg::CombinedData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__offboard_ros2__msg__CombinedData
    std::shared_ptr<offboard_ros2::msg::CombinedData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__offboard_ros2__msg__CombinedData
    std::shared_ptr<offboard_ros2::msg::CombinedData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CombinedData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->stair_pos_z != other.stair_pos_z) {
      return false;
    }
    if (this->vicon_posi_x != other.vicon_posi_x) {
      return false;
    }
    if (this->vicon_posi_y != other.vicon_posi_y) {
      return false;
    }
    if (this->vicon_posi_z != other.vicon_posi_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const CombinedData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CombinedData_

// alias to use template instance with default allocator
using CombinedData =
  offboard_ros2::msg::CombinedData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace offboard_ros2

#endif  // OFFBOARD_ROS2__MSG__DETAIL__COMBINED_DATA__STRUCT_HPP_
