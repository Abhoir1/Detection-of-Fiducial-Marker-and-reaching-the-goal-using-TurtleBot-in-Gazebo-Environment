set(_AMENT_PACKAGE_NAME "tb3_gazebo")
set(tb3_gazebo_VERSION "2.2.4")
set(tb3_gazebo_MAINTAINER "Will Son <willson@robotis.com>")
set(tb3_gazebo_BUILD_DEPENDS "gazebo_ros_pkgs" "geometry_msgs" "nav_msgs" "rclcpp" "sensor_msgs" "tf2")
set(tb3_gazebo_BUILDTOOL_DEPENDS "ament_cmake")
set(tb3_gazebo_BUILD_EXPORT_DEPENDS "gazebo_ros_pkgs" "geometry_msgs" "nav_msgs" "rclcpp" "sensor_msgs" "tf2")
set(tb3_gazebo_BUILDTOOL_EXPORT_DEPENDS )
set(tb3_gazebo_EXEC_DEPENDS "gazebo_ros_pkgs" "geometry_msgs" "nav_msgs" "rclcpp" "sensor_msgs" "tf2")
set(tb3_gazebo_TEST_DEPENDS )
set(tb3_gazebo_GROUP_DEPENDS )
set(tb3_gazebo_MEMBER_OF_GROUPS )
set(tb3_gazebo_DEPRECATED "")
set(tb3_gazebo_EXPORT_TAGS)
list(APPEND tb3_gazebo_EXPORT_TAGS "<build_type>ament_cmake</build_type>")
list(APPEND tb3_gazebo_EXPORT_TAGS "<gazebo_ros gazebo_model_path=\"models\"/>")
