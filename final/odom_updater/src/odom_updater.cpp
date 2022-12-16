<<<<<<< HEAD
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

=======
>>>>>>> 764b079224eb0f354e62bfaa8bdbd9b46f39bcd2
#include <string>
#include "odom_updater.h"
#include "tf2/LinearMath/Quaternion.h"
#include "geometry_msgs/msg/pose.hpp"
#include "rclcpp/rclcpp.hpp"

<<<<<<< HEAD
void OdomUpdater::timer_callback()
{
    broadcast_odom();
}

void OdomUpdater::broadcast_odom()
=======
void WorldOdomBroadcaster::timer_callback()
{
    broadcast_world_odom();
}

void WorldOdomBroadcaster::broadcast_world_odom()
>>>>>>> 764b079224eb0f354e62bfaa8bdbd9b46f39bcd2
{
    geometry_msgs::msg::TransformStamped t;

    std::string odom = "/robot1/odom";
<<<<<<< HEAD
    std::string footprint = "/robot1/base_footprint";

=======
    std::string origin1 = "origin1";
    std::string origin2 = "origin2";
    std::string origin3 = "origin3";
    std::string origin4 = "origin4";
>>>>>>> 764b079224eb0f354e62bfaa8bdbd9b46f39bcd2

    /*******************************************
     * static broadcaster: "world" -> "/robot1/odom"
     *******************************************/
    t.header.stamp = this->get_clock()->now();
<<<<<<< HEAD
    t.header.frame_id = odom;
    t.child_frame_id = footprint;
=======
    t.header.frame_id = "world";
    t.child_frame_id = odom;
>>>>>>> 764b079224eb0f354e62bfaa8bdbd9b46f39bcd2

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

<<<<<<< HEAD
=======
    /*******************************************
     * static broadcaster: "world" -> "origin1"
     *******************************************/
    t.header.stamp = this->get_clock()->now();
    t.header.frame_id = "world";
    t.child_frame_id = origin1;

    t.transform.translation.x = 2;
    t.transform.translation.y = 2;
    t.transform.translation.z = 0;

    // tf2::Quaternion q;
    q.setRPY(0, 0, 1.57);
    t.transform.rotation.x = q.x();
    t.transform.rotation.y = q.y();
    t.transform.rotation.z = q.z();
    t.transform.rotation.w = q.w();

    // Send the transformation
    m_tf_broadcaster->sendTransform(t);

    /*******************************************
     * static broadcaster: "world" -> "origin2"
     *******************************************/
    t.header.stamp = this->get_clock()->now();
    t.header.frame_id = "world";
    t.child_frame_id = origin2;

    t.transform.translation.x = -2;
    t.transform.translation.y = -2;
    t.transform.translation.z = 0;

    // tf2::Quaternion q;
    q.setRPY(0, 0, 1.57);
    t.transform.rotation.x = q.x();
    t.transform.rotation.y = q.y();
    t.transform.rotation.z = q.z();
    t.transform.rotation.w = q.w();

    // Send the transformation
    m_tf_broadcaster->sendTransform(t);

    /*******************************************
     * static broadcaster: "world" -> "origin3"
     *******************************************/
    t.header.stamp = this->get_clock()->now();
    t.header.frame_id = "world";
    t.child_frame_id = origin3;

    t.transform.translation.x = -2;
    t.transform.translation.y = 2;
    t.transform.translation.z = 0;

    // tf2::Quaternion q;
    q.setRPY(0, 0, 1.57);
    t.transform.rotation.x = q.x();
    t.transform.rotation.y = q.y();
    t.transform.rotation.z = q.z();
    t.transform.rotation.w = q.w();

    // Send the transformation
    m_tf_broadcaster->sendTransform(t);

    /*******************************************
     * static broadcaster: "world" -> "origin4"
     *******************************************/
    t.header.stamp = this->get_clock()->now();
    t.header.frame_id = "world";
    t.child_frame_id = origin4;

    t.transform.translation.x = 2;
    t.transform.translation.y = -2;
    t.transform.translation.z = 0;

    // tf2::Quaternion q;
    q.setRPY(0, 0, 1.57);
    t.transform.rotation.x = q.x();
    t.transform.rotation.y = q.y();
    t.transform.rotation.z = q.z();
    t.transform.rotation.w = q.w();

    // Send the transformation
    m_tf_broadcaster->sendTransform(t);
>>>>>>> 764b079224eb0f354e62bfaa8bdbd9b46f39bcd2
}

