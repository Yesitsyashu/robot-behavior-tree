# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(RobotBehaviorTree VERSION 1.0)

# Set C++ standard to C++17 (modern C++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add compiler warnings for better code quality
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Print status message
message(STATUS "===========================================")
message(STATUS "Building Robot Behavior Tree Project")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")

# Add the cmake path where BehaviorTree config is located
list(APPEND CMAKE_PREFIX_PATH /usr/local/share/behaviortree_cpp/cmake)

# Find BehaviorTree.CPP package
# The package is called "behaviortree_cpp" not "BehaviorTreeV3"
find_package(behaviortree_cpp REQUIRED)

if(behaviortree_cpp_FOUND)
    message(STATUS "BehaviorTree.CPP found!")
    message(STATUS "BehaviorTree version: ${behaviortree_cpp_VERSION}")
else()
    message(FATAL_ERROR "BehaviorTree.CPP not found!")
endif()

message(STATUS "===========================================")

# Create the executable from source file
add_executable(robot_behavior_tree 
    src/robot_behavior_tree.cpp
)

# Link the BehaviorTree library to our executable
# The target name is behaviortree_cpp, not BT::behaviortree_cpp
target_link_libraries(robot_behavior_tree
    behaviortree_cpp
)

# Set output directory for the executable
set_target_properties(robot_behavior_tree PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Installation rules (optional)
install(TARGETS robot_behavior_tree
    RUNTIME DESTINATION bin
)