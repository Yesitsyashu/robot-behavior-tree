#include <behaviortree_cpp/behavior_tree.h>
#include <behaviortree_cpp/bt_factory.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace BT;

//=============================================================================
// CUSTOM ACTION NODES - These are the robot's actions
//=============================================================================

/**
 * EnterRoom - Robot navigates to enter the room
 * This node simulates the robot moving through the door into the room
 */
class EnterRoom : public SyncActionNode
{
public:
    EnterRoom(const std::string& name, const NodeConfig& config)
        : SyncActionNode(name, config)
    {
        std::cout << "[Node Created] EnterRoom node initialized" << std::endl;
    }

    // Define the ports (input/output) - none needed for this simple action
    static PortsList providedPorts()
    {
        return {};
    }

    // This is called when the node is executed
    NodeStatus tick() override
    {
        std::cout << "\n┌─────────────────────────────────┐" << std::endl;
        std::cout << "│ [EnterRoom] EXECUTING           │" << std::endl;
        std::cout << "└─────────────────────────────────┘" << std::endl;
        
        std::cout << "  → Robot approaching room entrance..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  → Checking if path is clear..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  → Moving through doorway..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  ✓ Successfully entered the room!" << std::endl;
        
        return NodeStatus::SUCCESS;
    }
};

/**
 * OpenFridge - Robot opens the fridge door
 * This simulates the manipulation task of opening the fridge
 */
class OpenFridge : public SyncActionNode
{
public:
    OpenFridge(const std::string& name, const NodeConfig& config)
        : SyncActionNode(name, config)
    {
        std::cout << "[Node Created] OpenFridge node initialized" << std::endl;
    }

    static PortsList providedPorts()
    {
        return {};
    }

    NodeStatus tick() override
    {
        std::cout << "\n┌─────────────────────────────────┐" << std::endl;
        std::cout << "│ [OpenFridge] EXECUTING          │" << std::endl;
        std::cout << "└─────────────────────────────────┘" << std::endl;
        
        std::cout << "  → Navigating to fridge location..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  → Detecting fridge handle..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  → Grasping handle with gripper..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  → Pulling door open..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  ✓ Fridge is now open!" << std::endl;
        
        return NodeStatus::SUCCESS;
    }
};

/**
 * PickApple - Robot picks an apple from the fridge
 * This simulates object detection and grasping
 */
class PickApple : public SyncActionNode
{
public:
    PickApple(const std::string& name, const NodeConfig& config)
        : SyncActionNode(name, config)
    {
        std::cout << "[Node Created] PickApple node initialized" << std::endl;
    }

    static PortsList providedPorts()
    {
        return {};
    }

    NodeStatus tick() override
    {
        std::cout << "\n┌─────────────────────────────────┐" << std::endl;
        std::cout << "│ [PickApple] EXECUTING           │" << std::endl;
        std::cout << "└─────────────────────────────────┘" << std::endl;
        
        std::cout << "  → Scanning fridge contents..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  → Apple detected at position (x:0.3, y:0.5, z:1.2)..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  → Moving arm to apple position..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  → Closing gripper around apple..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  → Lifting apple..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  ✓ Apple successfully picked!" << std::endl;
        
        return NodeStatus::SUCCESS;
    }
};

/**
 * ExitRoom - Robot navigates to exit the room
 * This simulates the robot leaving the room
 */
class ExitRoom : public SyncActionNode
{
public:
    ExitRoom(const std::string& name, const NodeConfig& config)
        : SyncActionNode(name, config)
    {
        std::cout << "[Node Created] ExitRoom node initialized" << std::endl;
    }

    static PortsList providedPorts()
    {
        return {};
    }

    NodeStatus tick() override
    {
        std::cout << "\n┌─────────────────────────────────┐" << std::endl;
        std::cout << "│ [ExitRoom] EXECUTING            │" << std::endl;
        std::cout << "└─────────────────────────────────┘" << std::endl;
        
        std::cout << "  → Planning path to exit..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  → Navigating to doorway..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  → Passing through exit..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "  ✓ Successfully exited the room!" << std::endl;
        std::cout << "  🎉 MISSION COMPLETE!" << std::endl;
        
        return NodeStatus::SUCCESS;
    }
};

//=============================================================================
// MAIN FUNCTION
//=============================================================================

int main()
{
    std::cout << "\n";
    std::cout << "╔═══════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                                                   ║" << std::endl;
    std::cout << "║        ROBOT BEHAVIOR TREE DEMONSTRATION          ║" << std::endl;
    std::cout << "║                                                   ║" << std::endl;
    std::cout << "║  Task: Enter Room → Open Fridge → Pick Apple     ║" << std::endl;
    std::cout << "║        → Exit Room                                ║" << std::endl;
    std::cout << "║                                                   ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════════════╝" << std::endl;
    std::cout << "\n";

    // Step 1: Create a BehaviorTreeFactory
    // This factory will store all our custom nodes
    std::cout << "═══════════════════════════════════════════════════" << std::endl;
    std::cout << "INITIALIZATION PHASE" << std::endl;
    std::cout << "═══════════════════════════════════════════════════" << std::endl;
    
    BehaviorTreeFactory factory;
    std::cout << "[Factory] BehaviorTreeFactory created" << std::endl;

    // Step 2: Register all our custom action nodes with the factory
    // The factory needs to know about our nodes before we can use them
    std::cout << "\n[Registering Nodes]" << std::endl;
    factory.registerNodeType<EnterRoom>("EnterRoom");
    factory.registerNodeType<OpenFridge>("OpenFridge");
    factory.registerNodeType<PickApple>("PickApple");
    factory.registerNodeType<ExitRoom>("ExitRoom");
    std::cout << "[Registration Complete] All nodes registered successfully" << std::endl;

    // Step 3: Define the Behavior Tree structure in XML format
    // This is where we define the FLOW of the robot's behavior
    static const char* xml_text = R"(
    <root BTCPP_format="4">
        <BehaviorTree ID="RobotTask">
            <Sequence name="MainSequence">
                <EnterRoom name="enter_room"/>
                <OpenFridge name="open_fridge"/>
                <PickApple name="pick_apple"/>
                <ExitRoom name="exit_room"/>
            </Sequence>
        </BehaviorTree>
    </root>
    )";

    std::cout << "\n[Tree Definition]" << std::endl;
    std::cout << "Behavior Tree Structure:" << std::endl;
    std::cout << "  Sequence (executes children in order)" << std::endl;
    std::cout << "    ├── EnterRoom" << std::endl;
    std::cout << "    ├── OpenFridge" << std::endl;
    std::cout << "    ├── PickApple" << std::endl;
    std::cout << "    └── ExitRoom" << std::endl;

    // Step 4: Create the tree from the XML definition
    std::cout << "\n[Creating Tree] Building behavior tree from XML..." << std::endl;
    auto tree = factory.createTreeFromText(xml_text);
    std::cout << "[Tree Created] Behavior tree successfully built!" << std::endl;

    // Step 5: Execute the behavior tree
    std::cout << "\n";
    std::cout << "═══════════════════════════════════════════════════" << std::endl;
    std::cout << "EXECUTION PHASE" << std::endl;
    std::cout << "═══════════════════════════════════════════════════" << std::endl;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // tick() runs the tree once, executing nodes according to the structure
    NodeStatus status = tree.tickWhileRunning();

    // Step 6: Report final status
    std::cout << "\n";
    std::cout << "═══════════════════════════════════════════════════" << std::endl;
    std::cout << "FINAL REPORT" << std::endl;
    std::cout << "═══════════════════════════════════════════════════" << std::endl;
    
    if (status == NodeStatus::SUCCESS)
    {
        std::cout << "Status: ✓ SUCCESS" << std::endl;
        std::cout << "Result: All tasks completed successfully!" << std::endl;
        std::cout << "The robot has completed the mission." << std::endl;
    }
    else if (status == NodeStatus::FAILURE)
    {
        std::cout << "Status: ✗ FAILURE" << std::endl;
        std::cout << "Result: One or more tasks failed." << std::endl;
    }
    else
    {
        std::cout << "Status: ○ RUNNING" << std::endl;
        std::cout << "Result: Tree is still executing." << std::endl;
    }

    std::cout << "═══════════════════════════════════════════════════" << std::endl;
    std::cout << "\n";

    return 0;
}