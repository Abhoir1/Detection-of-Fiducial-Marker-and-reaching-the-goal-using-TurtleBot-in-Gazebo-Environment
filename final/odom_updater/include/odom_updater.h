#pragma once

#include "rclcpp/rclcpp.hpp"
#include <nav_msgs/msg/odometry.hpp>
#include "tf2/LinearMath/Quaternion.h"
#include "geometry_msgs/msg/pose.hpp"
#include "tf2_ros/static_transform_broadcaster.h"
#include <string>

class odom_updater : public rclcpp::Node
{
public:
    odom_updater(std::string node_name) : Node(node_name)
    {
        // Initialize the transform broadcaster
        m_tf_broadcaster =
            std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);

        // Create a timer
        m_timer = this->create_wall_timer(std::chrono::milliseconds((int)(1000.0 / 1.0)),
                                          std::bind(&odom_updater::timer_callback, this));
    }

private:
    // attributes
    rclcpp::TimerBase::SharedPtr m_timer;
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> m_tf_broadcaster;

    // methods
    void broadcast_odom();
    void timer_callback();
};