#pragma once

#include "rclcpp/rclcpp.hpp"
#include <nav_msgs/msg/odometry.hpp>
#include "tf2/LinearMath/Quaternion.h"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include <string>
#include <sstream>

class odom_updater : public rclcpp::Node
{
public:
    odom_updater(std::string node_name) : Node(node_name)
    {
        // Initialize the transform broadcaster
        m_tf_broadcaster =
            std::make_unique<tf2_ros::TransformBroadcaster>(this);

        // Create a timer
        // m_timer = this->create_wall_timer(std::chrono::milliseconds((int)(1000.0 / 1.0)),
                                        //   std::bind(&odom_updater::timer_callback, this));

        // Subscribe to a /robot1/odom topic and call timer_callback
        m_tf_subscription = this->create_subscription<nav_msgs::msg::Odometry>
        ("/robot1/odom", 10, std::bind(&odom_updater::timer_callback, this, std::placeholders::_1));                                  
    }

private:
    // attributes
    // rclcpp::TimerBase::SharedPtr m_timer;

    // Shared pointer to a Subscription object for the /robot1/odom topic
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr m_tf_subscription;
    
    std::unique_ptr<tf2_ros::TransformBroadcaster> m_tf_broadcaster;

    // methods
    // void broadcast_odom(const std::shared_ptr<nav_msgs::msg::Odometry> msg);
    void timer_callback(const std::shared_ptr<nav_msgs::msg::Odometry> msg);
};
