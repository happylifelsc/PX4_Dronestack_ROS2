# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:offboard_ros2__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:offboard_ros2__rosidl_typesupport_fastrtps_c;__rosidl_generator_cpp:offboard_ros2__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:offboard_ros2__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_c:offboard_ros2__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:offboard_ros2__rosidl_typesupport_c;__rosidl_typesupport_introspection_cpp:offboard_ros2__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:offboard_ros2__rosidl_typesupport_cpp;__rosidl_generator_py:offboard_ros2__rosidl_generator_py")

# populate offboard_ros2_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "offboard_ros2::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'offboard_ros2' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND offboard_ros2_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
