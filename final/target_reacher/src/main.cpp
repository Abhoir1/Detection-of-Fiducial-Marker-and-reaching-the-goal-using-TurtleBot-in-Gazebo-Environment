#include <rclcpp/rclcpp.hpp>
#include "target_reacher/target_reacher.h"
#include "bot_controller/bot_controller.h"

int main(int argc, char *argv[])
{
    // init
    // rclcpp::init(argc, argv);
    // // node
    // auto bot_controller = std::make_shared<BotController>("bot_controller_robot2", "robot2");
    // auto node = std::make_shared<MoveInCircle>("move_in_circle_robot2", bot_controller);
    // rclcpp::spin(node);
    // // shutdown
    // rclcpp::shutdown();

    rclcpp::init(argc, argv);
    auto bot_controller = std::make_shared<BotController>("bot_controller_robot", "robot1");
    rclcpp::executors::MultiThreadedExecutor exec;
    auto node = std::make_shared<TargetReacher>(bot_controller);
    exec.add_node(node);
    exec.add_node(bot_controller);
    exec.spin();
    rclcpp::shutdown();
}