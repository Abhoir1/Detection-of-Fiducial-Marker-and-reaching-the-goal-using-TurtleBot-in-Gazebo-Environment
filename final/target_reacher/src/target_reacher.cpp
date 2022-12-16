#include <rclcpp/rclcpp.hpp>
#include "target_reacher.h"

void TargetReacher::final_destination(int goal)
{
        geometry_msgs::msg::TransformStamped g;

        g.header.stamp = this->get_clock()->now();
        g.header.frame_id = frame_id;
        g.child_frame_id = "final_destination";

        if (goal==0)
        {
            g.transform.translation.x = aruco_0_x;
            g.transform.translation.y = aruco_0_y;
            g.transform.translation.z = 0.0;
        }else if (goal==1)
        {
            g.transform.translation.x = aruco_1_x;
            g.transform.translation.y = aruco_1_y;
            g.transform.translation.z = 0.0;
        }else if (goal==2)
        {
            g.transform.translation.x = aruco_2_x;
            g.transform.translation.y = aruco_2_y;
            g.transform.translation.z = 0.0;
        }else if (goal==3)
        {
            g.transform.translation.x = aruco_3_x;
            g.transform.translation.y = aruco_3_y;
            g.transform.translation.z = 0.0;
        } 

        g.transform.rotation.x = 0.0;
        g.transform.rotation.y = 0.0;
        g.transform.rotation.z = 0.0;
        g.transform.rotation.w = 1.0;

        final_destination_broadcaster->sendTransform(g);

        i=true;
}

void TargetReacher::cb1(const std::shared_ptr<ros2_aruco_interfaces::msg::ArucoMarkers> aruco)
{
    auto x = aruco->marker_ids;
    if (x.at(0)==0){
        auto goal=0;
        final_destination(goal);
    }else if (x.at(0)==1){
        auto goal=1;
        final_destination(goal);
    }else if (x.at(0)==2){
        auto goal=2;
        final_destination(goal);
    }else if (x.at(0)==3){
        auto goal=3;
        final_destination(goal);
    }
}

void TargetReacher::timer_callback(const std::shared_ptr<std_msgs::msg::Bool> msg)
{
    if (msg->data)
    {
        geometry_msgs::msg::Twist vel;
        vel.linear.x = 0;
        vel.angular.z = 0.2;
        cmd_vel_publisher->publish(vel);

        ros2_aruco_interfaces::msg::ArucoMarkers aruco;

    }
}

void TargetReacher::cb2()
{
    if (i==true)
    {
        geometry_msgs::msg::TransformStamped t;
        // Look up for the transformation between "robot1/odom" and "final_destination" frames
        try
        {
            t = tf_buffer->lookupTransform("robot1/odom", "final_destination", tf2::TimePointZero);
        }
        catch (const tf2::TransformException &ex)
        {
            RCLCPP_INFO(
                this->get_logger(), "Could not transform %s to %s: %s",
                "robot1/odom", "final_destination", ex.what());
            return;
        }

        RCLCPP_INFO(
            this->get_logger(), "Moving to goal [%f, %f]", t.transform.translation.x, t.transform.translation.y);

        m_bot_controller->set_goal(t.transform.translation.x, t.transform.translation.y);
    }
}


