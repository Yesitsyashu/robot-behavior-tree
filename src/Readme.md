# Robot Behavior Tree Project

## Overview
This project implements a Behavior Tree in C++ to control a robot performing a sequence of tasks:
1. Enter a room
2. Open a fridge
3. Pick an apple
4. Exit the room

## Project Structure
```
robot_behavior_tree/
├── CMakeLists.txt              # Build configuration
├── src/
│   └── robot_behavior_tree.cpp # Main source code
└── README.md                   # This file
```

## Prerequisites
- Ubuntu 20.04 or later
- C++17 compiler (GCC/G++)
- CMake 3.10+
- BehaviorTree.CPP library

## Building the Project

### 1. Navigate to project directory
```bash
cd ~/bt_ws/src/robot_behavior_tree
```

### 2. Create build directory
```bash
mkdir -p build
cd build
```

### 3. Run CMake
```bash
cmake ..
```

### 4. Compile
```bash
make
```

### 5. Run the executable
```bash
./bin/robot_behavior_tree
```

## Code Explanation

### Custom Action Nodes
Each action is implemented as a class inheriting from `SyncActionNode`:

- **EnterRoom**: Simulates robot navigation into the room
- **OpenFridge**: Simulates opening the fridge door
- **PickApple**: Simulates detecting and grasping an apple
- **ExitRoom**: Simulates robot navigation out of the room

### Behavior Tree Structure
Uses a **Sequence** node that executes children in order:
- If any child returns FAILURE, the sequence stops and returns FAILURE
- If all children return SUCCESS, the sequence returns SUCCESS

## Expected Output
The program will display:
1. Initialization phase (registering nodes, creating tree)
2. Execution phase (each action's detailed steps)
3. Final report (success/failure status)

## Learning Resources
- [BehaviorTree.CPP Documentation](https://www.behaviortree.dev/)
- [Behavior Trees Overview](https://en.wikipedia.org/wiki/Behavior_tree_(artificial_intelligence,_robotics_and_control))

## Author
Created for robotics behavior tree demonstration
