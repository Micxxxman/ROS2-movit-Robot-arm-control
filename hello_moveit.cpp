#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
using namespace  std;

//https://roboticscasual.com/ros-tutorial-pick-and-place-task-with-the-moveit-c-interface/
//https://stackoverflow.com/questions/66988200/how-can-i-manipulate-ur5-by-ros-moveit

//define pi _USE_MATH_DEFINES;
//#define pi  3.14159265358979323846;
int contorl_signal_joint(int argc,auto argv,double j1,double j2,double j3,double j4,double j5,double j6){

double a1 = j1*M_PI/180;
double a2 = j2*M_PI/180;
double a3 = j3*M_PI/180;
double a4 = j4*M_PI/180;
double a5 = j5*M_PI/180;
double a6 = j6*M_PI/180;
const std::vector<double> camer_joint = {a1,a2,a3,a4,a5,a6};
rclcpp::init(argc,argv);
 auto const node = std::make_shared<rclcpp::Node>(
  "hello_moveit", rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));
  auto const logger = rclcpp::get_logger("hjellow_moveit");
 using moveit::planning_interface::MoveGroupInterface;
  auto moveit_group_interface_joint = MoveGroupInterface(node, "lamRobot");
  moveit_group_interface_joint.setJointValueTarget(camer_joint);
  auto const[success2,plan2] =[&moveit_group_interface_joint]{
 moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(moveit_group_interface_joint.plan(msg));
    return std::make_pair(ok, msg);
  }();
  if(success2){
    moveit_group_interface_joint.execute(plan2);

  }else{
    RCLCPP_ERROR(logger, "Planing failed!");

  }
   rclcpp::shutdown();
   return 0;

 }


int control_gripper(int argc,auto argv,string gripper_motion){
 rclcpp::init(argc,argv);
 auto const node = std::make_shared<rclcpp::Node>(
  "hello_moveit", rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));
  auto const logger = rclcpp::get_logger("hjellow_moveit");
 using moveit::planning_interface::MoveGroupInterface;
  auto moveit_group_interface_gripper = MoveGroupInterface(node, "hand");
  moveit_group_interface_gripper.setJointValueTarget(moveit_group_interface_gripper.getNamedTargetValues(gripper_motion));
  auto const[success2,plan2] =[&moveit_group_interface_gripper]{
 moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(moveit_group_interface_gripper.plan(msg));
    return std::make_pair(ok, msg);
  }();
  if(success2){
    moveit_group_interface_gripper.execute(plan2);

  }else{
    RCLCPP_ERROR(logger, "Planing failed!");

  }
   rclcpp::shutdown();
   return 0;


}



int control_arm(int argc, auto argv,double X,double Y,double Z){
  
rclcpp::init(argc, argv);
  auto const node = std::make_shared<rclcpp::Node>(
      "hello_moveit", rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));

  // Create a ROS logger
  auto const logger = rclcpp::get_logger("hello_moveit");

  // Create the MoveIt MoveGroup Interface
  using moveit::planning_interface::MoveGroupInterface;
  geometry_msgs::msg::PoseStamped current_pose;
  //geometry_msgs::PoseStamped current_pose;
  auto moveit_group_interface = MoveGroupInterface(node, "lamRobot");

  // Set a target Pose
  auto const target_pose = [&X,&Y,&Z,&current_pose] {
    geometry_msgs::msg::Pose msg;
    msg.orientation.w = -1;
    msg.position.x =X;
    msg.position.y = Y;
    msg.position.z = Z;
    return msg;
  }();
  moveit_group_interface.setPoseTarget(target_pose);

  // Create a plan to that target pose
  auto const [success, plan] = [&moveit_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(moveit_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  // Execute the plan
  if (success)
  {
    moveit_group_interface.execute(plan);
  }
  else
  {
    RCLCPP_ERROR(logger, "Planing failed!");
  }

  // Shutdown ROS
  rclcpp::shutdown();
  return 0;

    }

    
     



int main(int argc, char* argv[])
{  

  while (true){
  double a,b,c,d,e,f;
 
  std::cin >>a>>b>>c>>d>>e>>f;
cout<<a<<b<<c<<d<<e<<f<<endl;
  contorl_signal_joint(argc,argv,a,b,c,d,e,f);
  //control_arm(argc,argv,X,Y,Z);

char S;
std::cin >>S;
  if(S == 'p')
  {
    control_gripper(argc,argv,"pick");
  }
  if(S== 'r'){

    control_gripper(argc,argv,"release");
  }
  // Initialize ROS and create the Node
  }
  
}
