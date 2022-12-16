#pragma once

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <string>
#include "bot_controller/bot_controller.h"
#include "ros2_aruco_interfaces/msg/aruco_markers.hpp"
#include "tf2_ros/static_transform_broadcaster.h"

// timer
class TargetReacher : public rclcpp::Node
{
public:
    TargetReacher(std::shared_ptr<BotController> const &bot_controller) : Node("target_reacher")
    {

        m_bot_controller = bot_controller;
        
        auto goal_x = this->declare_parameter<double>("aruco_target.x");
        auto goal_y = this->declare_parameter<double>("aruco_target.y");

        auto frame_id = this->declare_parameter<std::string>("final_destination.frame_id");

        auto aruco_0_x = this->declare_parameter<double>("final_destination.aruco_0.x");
        auto aruco_0_y = this->declare_parameter<double>("final_destination.aruco_0.y");

        auto aruco_1_x = this->declare_parameter<double>("final_destination.aruco_1.x");
        auto aruco_1_y = this->declare_parameter<double>("final_destination.aruco_1.y");

        auto aruco_2_x = this->declare_parameter<double>("final_destination.aruco_2.x");
        auto aruco_2_y = this->declare_parameter<double>("final_destination.aruco_2.y");

        auto aruco_3_x = this->declare_parameter<double>("final_destination.aruco_3.x");
        auto aruco_3_y = this->declare_parameter<double>("final_destination.aruco_3.y");

        m_bot_controller->set_goal(goal_x,goal_y);
    }

private:
    // attributes
    std::shared_ptr<BotController> m_bot_controller;
};