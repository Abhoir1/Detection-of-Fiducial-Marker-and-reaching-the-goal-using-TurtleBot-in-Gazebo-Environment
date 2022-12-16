// #pragma once

// #include <string>
// #include <rclcpp/rclcpp.hpp>
// #include <geometry_msgs/msg/twist.hpp>
// #include <string>
// #include "bot_controller/bot_controller.h"
// #include "ros2_aruco_interfaces/msg/aruco_markers.hpp"
// #include "tf2_ros/static_transform_broadcaster.h"

// // timer
// class OdomUpdater : public rclcpp::Node
// {
// public:
//     FramePublisher()
//         : Node("odom_updater")
//     // OdomUpdater(std::shared_ptr<BotController> const &bot_controller) : Node("target_reacher")
//     {
//         tf_broadcaster = std :: make_unique<tf2_ros::StaticTransformBroadcaster>(this);
//         m_timer = this->create_wall_timer(std::chrono::milliseconds((int)(1000.0 / 10)),
//                                           std::bind(&FramePublisher::timer_callback, this));

//     }
// private:
//     void timer_callback()

//     {

//         geometry_msgs::msg::TransformStamped t;
        
//         t.header.stamp = this->get_clock()->now();
//         t.header.frame_id = odom;
//         t.child_frame_id = "/robot1/base_footprint";

//         m_tf_broadcaster ->sendTransform();

//     }
//     std::shared_ptr<tf2_ros::StaticTransformBroadcaster> m_tf_broadcaster;
//     rclcpp::TimerBase::SharedPtr m_timer;
// };

// int main(int argc, chae *argv[])
// {
//     rclcpp::init(argc, argv);
//     rclcpp::spin(std::make_shared<FramePublisher>());
//     rclcpp::shutdown();
//     return 0;
// }

#include <string>
#include "odom_updater.h"
#include "tf2/LinearMath/Quaternion.h"
#include "geometry_msgs/msg/pose.hpp"
#include "rclcpp/rclcpp.hpp"

void odom_updater::timer_callback()
{
    broadcast_odom();
}

void odom_updater::broadcast_odom()
{
    geometry_msgs::msg::TransformStamped t;

    std::string odom = "/robot1/odom";
    std::string footprint = "/robot1/base_footprint";


    /*******************************************
     * Broadcaster: "/robot1/odom" -> "/robot1/base_footprint
     *******************************************/
    t.header.stamp = this->get_clock()->now();
    t.header.frame_id = odom;
    t.child_frame_id = footprint;

    t.transform.translation.x = 0;
    t.transform.translation.y = 0;
    t.transform.translation.z = 0;

    tf2::Quaternion q;
    q.setRPY(0, 0, 0);
    t.transform.rotation.x = q.x();
    t.transform.rotation.y = q.y();
    t.transform.rotation.z = q.z();
    t.transform.rotation.w = q.w();

    // Send the transformation
    m_tf_broadcaster->sendTransform(t);

}

