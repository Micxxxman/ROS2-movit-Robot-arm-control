[![Tests](https://github.com/m-lundberg/simple-pid/actions/workflows/run-tests.yml/badge.svg)](https://github.com/m-lundberg/simple-pid/actions?query=workflow%3Atests)
[![PyPI](https://img.shields.io/pypi/v/simple-pid.svg)](https://pypi.org/project/simple-pid/)
[![Read the Docs](https://img.shields.io/readthedocs/simple-pid.svg)](https://simple-pid.readthedocs.io/)
[![License](https://img.shields.io/github/license/m-lundberg/simple-pid.svg)](https://github.com/m-lundberg/simple-pid/blob/master/LICENSE.md)
[![Downloads](https://pepy.tech/badge/simple-pid)](https://pepy.tech/project/simple-pid)
[![Code style: black](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/psf/black)

# ROS2-movit-Robot-arm-control


control the robot arm in the ubuntn 22.04LTS
install the ROS Humble accroding to your computer CPU, ROS Humble just for my case 
reference :https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html
install the movit2 
reference :https://moveit.picknik.ai/humble/doc/tutorials/getting_started/getting_started.html
create the warkpase and pull the package to ros scr file 
reference : https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Creating-A-Workspace/Creating-A-Workspace.html
generate a urdf 
reference :https://www.youtube.com/watch?v=p9c9KoKjEe0
reference :https://www.youtube.com/watch?v=OSL-zqw4cXs
change the urdf CMakeLists.txt file and package.xml you can refer the my CMakeLists.txt file and package.xml, it is noly to modify the project name.
 
 command "colcon build"
