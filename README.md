

# ROS2-movit-Robot-arm-control


control the robot arm in the ubuntn 22.04LTS
install the ROS Humble accroding to your computer CPU, ROS Humble just for my case 
reference :https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html


```
install the movit2 

```

reference :https://moveit.picknik.ai/humble/doc/tutorials/getting_started/getting_started.html

```
create the warkpase and pull the package to ros scr file 

```

reference : https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Creating-A-Workspace/Creating-A-Workspace.html


```
generate a urdf 

```
reference :https://www.youtube.com/watch?v=p9c9KoKjEe0

reference :https://www.youtube.com/watch?v=OSL-zqw4cXs

change the urdf CMakeLists.txt file and package.xml you can refer the my CMakeLists.txt file and package.xml, it is noly to modify the project name.

```
cd your_workspace
```
```
"colcon build"
```
```
source install/setup.bash 
```
follow the tutorials to load your urdf file and generate the conflg file  

http://docs.ros.org/en/kinetic/api/moveit_tutorials/html/doc/setup_assistant/setup_assistant_tutorial.html

you must to add some part in your conflg file, go to yor conflg launch and select the demo.launc.py add
```
def lunch_setup(context, *args,**kwargs):
    
    
    
     # Start the actual move_group node/action server
    run_move_group_node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",
        parameters=[moveit_config.to_dict()],
    )
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config],
        parameters=[
            moveit_config.robot_description,
            moveit_config.robot_description_semantic,
            moveit_config.robot_description_kinematics,
            moveit_config.planning_pipelines,
            moveit_config.joint_limits,
        ],
    )
    
  # Publish TF
    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="both",
        parameters=[moveit_config.robot_description],
    )
    
    ros2_control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[moveit_config.robot_description, ros2_controllers_path],
        output="both",
    )
    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "joint_state_broadcaster",
            "--controller-manager-timeout",
            "300",
            "--controller-manager",
            "/controller_manager",
        ],
    )
    nodes_to_start = [
        rviz_node,
        robot_state_publisher,
        run_move_group_node,
        ros2_control_node,
        joint_state_broadcaster_spawner,
        arm_controller_spawner,
        hand_controller_spawner,
    ]
       
    return nodes_to_start
``` 
and 
```
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.conditions import IfCondition, UnlessCondition
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import ExecuteProcess

```
[Screencast from 04-17-2023 11:50:02 PM.webm](https://user-images.githubusercontent.com/82942566/232541835-a55ebf8e-f60b-4133-945c-21e99adcf41b.webm)


