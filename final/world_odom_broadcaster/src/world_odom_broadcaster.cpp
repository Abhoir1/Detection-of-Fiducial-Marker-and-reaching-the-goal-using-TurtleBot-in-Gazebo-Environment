#include <string>
#include "world_odom_broadcaster.h"
#include "tf2/LinearMath/Quaternion.h"
#include "geometry_msgs/msg/pose.hpp"
#include "rclcpp/rclcpp.hpp"

void WorldOdomBroadcaster::timer_callback()
{
    broadcast_world_odom();
}

void WorldOdomBroadcaster::broadcast_world_odom()
{
    geometry_msgs::msg::TransformStamped t;

    std::string odom1 = "/robot1/odom";
    // std::string odom3 = "/robot3/odom";

    t.header.stamp = this->get_clock()->now();
    t.header.frame_id = "world";
    t.child_frame_id = odom1;

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

