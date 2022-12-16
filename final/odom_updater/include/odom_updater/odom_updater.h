// #pragma once

// #include "rclcpp/rclcpp.hpp"
// #include <nav_msgs/msg/odometry.hpp>
// #include "tf2/LinearMath/Quaternion.h"
// #include "geometry_msgs/msg/pose.hpp"
// #include "tf2_ros/transform_broadcaster.h"
// #include <string>

// class odom_updater : public rclcpp::Node
// {
// public:
//     odom_updater(std::string node_name) : Node(node_name)
//     {
//         // Initialize the transform broadcaster
//         m_tf_broadcaster =
//             std::make_shared<tf2_ros::TransformBroadcaster>(this);

//         // Create a timer
//         m_timer = this->create_wall_timer(std::chrono::milliseconds((int)(1000.0 / 1.0)),
//                                           std::bind(&odom_updater::timer_callback, this));
//     }

// private:
//     // attributes
//     rclcpp::TimerBase::SharedPtr m_timer;
//     std::shared_ptr<tf2_ros::TransformBroadcaster> m_tf_broadcaster;

//     // methods
//     void broadcast_odom();
//     void timer_callback();
// };

#pragma once

#include <sstream>
#include <string>


#include "geometry_msgs/msg/transform_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include <nav_msgs/msg/odometry.hpp>


/**
 * @brief Node for publishing odometry data as a TransformStamped message.
 * 
 * This node subscribes to a "/robot1/odom" topic and broadcasts the odometry data in the form of a
 * TransformStamped message. The message contains the position and orientation of the robot relative
 * to the "/robot1/odom" frame, and specifies that the data is associated with the
 * "/robot1/base_footprint" frame.
 */


class FramePublisher : public rclcpp::Node
{
public:

  /**
   * @brief Constructs a new FramePublisher object.
   * 
   * Initializes the node and sets up a subscription to the "/robot1/odom" topic. The timer_callback
   * function is called whenever new odometry data is received on this topic.
   */

  FramePublisher()
  : Node("odom_updater")
  {
    // Initialize the transform broadcaster
    tf_broadcaster = std::make_unique<tf2_ros::TransformBroadcaster>(this);


    // Subscribe to a /robot1/odom topic and call timer_callback
    tf_subscription = this->create_subscription<nav_msgs::msg::Odometry>("/robot1/odom", 10, std::bind(&FramePublisher::timer_callback, this, std::placeholders::_1));
  }

private:

  /**
   * @brief Callback function for processing odometry data.
   * 
   * This function is called whenever new odometry data is received on the "/robot1/odom" topic. It
   * extracts the position and orientation data from the input message and broadcasts it as a
   * TransformStamped message.
   * 
   * @param msg Shared pointer to a nav_msgs::msg::Odometry message containing the odometry data.
   */

  void timer_callback(const std::shared_ptr<nav_msgs::msg::Odometry> msg);
  
    // Shared pointer to a Subscription object for the /robot1/odom topic
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr tf_subscription;

    // Unique pointer to a TransformBroadcaster object for sending TransformStamped messages
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster;
};

/**
 * @brief Main function for the odom_updater node.
 * 
 * This function initializes the ROS2 system, creates an instance of the FramePublisher class, and
 * starts the node's event loop.
 */

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<FramePublisher>());
  rclcpp::shutdown();
  return 0;
}