// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from offboard_ros2:msg/CombinedData.idl
// generated code does not contain a copyright notice
#include "offboard_ros2/msg/detail/combined_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
offboard_ros2__msg__CombinedData__init(offboard_ros2__msg__CombinedData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    offboard_ros2__msg__CombinedData__fini(msg);
    return false;
  }
  // stair_pos_z
  // vicon_posi_x
  // vicon_posi_y
  // vicon_posi_z
  return true;
}

void
offboard_ros2__msg__CombinedData__fini(offboard_ros2__msg__CombinedData * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // stair_pos_z
  // vicon_posi_x
  // vicon_posi_y
  // vicon_posi_z
}

bool
offboard_ros2__msg__CombinedData__are_equal(const offboard_ros2__msg__CombinedData * lhs, const offboard_ros2__msg__CombinedData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // stair_pos_z
  if (lhs->stair_pos_z != rhs->stair_pos_z) {
    return false;
  }
  // vicon_posi_x
  if (lhs->vicon_posi_x != rhs->vicon_posi_x) {
    return false;
  }
  // vicon_posi_y
  if (lhs->vicon_posi_y != rhs->vicon_posi_y) {
    return false;
  }
  // vicon_posi_z
  if (lhs->vicon_posi_z != rhs->vicon_posi_z) {
    return false;
  }
  return true;
}

bool
offboard_ros2__msg__CombinedData__copy(
  const offboard_ros2__msg__CombinedData * input,
  offboard_ros2__msg__CombinedData * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // stair_pos_z
  output->stair_pos_z = input->stair_pos_z;
  // vicon_posi_x
  output->vicon_posi_x = input->vicon_posi_x;
  // vicon_posi_y
  output->vicon_posi_y = input->vicon_posi_y;
  // vicon_posi_z
  output->vicon_posi_z = input->vicon_posi_z;
  return true;
}

offboard_ros2__msg__CombinedData *
offboard_ros2__msg__CombinedData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  offboard_ros2__msg__CombinedData * msg = (offboard_ros2__msg__CombinedData *)allocator.allocate(sizeof(offboard_ros2__msg__CombinedData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(offboard_ros2__msg__CombinedData));
  bool success = offboard_ros2__msg__CombinedData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
offboard_ros2__msg__CombinedData__destroy(offboard_ros2__msg__CombinedData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    offboard_ros2__msg__CombinedData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
offboard_ros2__msg__CombinedData__Sequence__init(offboard_ros2__msg__CombinedData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  offboard_ros2__msg__CombinedData * data = NULL;

  if (size) {
    data = (offboard_ros2__msg__CombinedData *)allocator.zero_allocate(size, sizeof(offboard_ros2__msg__CombinedData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = offboard_ros2__msg__CombinedData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        offboard_ros2__msg__CombinedData__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
offboard_ros2__msg__CombinedData__Sequence__fini(offboard_ros2__msg__CombinedData__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      offboard_ros2__msg__CombinedData__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

offboard_ros2__msg__CombinedData__Sequence *
offboard_ros2__msg__CombinedData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  offboard_ros2__msg__CombinedData__Sequence * array = (offboard_ros2__msg__CombinedData__Sequence *)allocator.allocate(sizeof(offboard_ros2__msg__CombinedData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = offboard_ros2__msg__CombinedData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
offboard_ros2__msg__CombinedData__Sequence__destroy(offboard_ros2__msg__CombinedData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    offboard_ros2__msg__CombinedData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
offboard_ros2__msg__CombinedData__Sequence__are_equal(const offboard_ros2__msg__CombinedData__Sequence * lhs, const offboard_ros2__msg__CombinedData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!offboard_ros2__msg__CombinedData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
offboard_ros2__msg__CombinedData__Sequence__copy(
  const offboard_ros2__msg__CombinedData__Sequence * input,
  offboard_ros2__msg__CombinedData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(offboard_ros2__msg__CombinedData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    offboard_ros2__msg__CombinedData * data =
      (offboard_ros2__msg__CombinedData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!offboard_ros2__msg__CombinedData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          offboard_ros2__msg__CombinedData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!offboard_ros2__msg__CombinedData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
