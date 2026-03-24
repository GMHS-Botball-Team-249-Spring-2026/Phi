#include "Arm.hpp"
#include "DriveTrain.hpp"
#include <iostream>
#include <kipr/wombat.h>

// Constants for arm positions
namespace ShoulderPositions
{
    constexpr int DOWN = 1900;
    constexpr int UP = 830;
}

namespace ElbowPositions
{
    constexpr int DOWN = 0;
    constexpr int UP = 0;
}

namespace ClawPositions
{
    constexpr int CLOSED = 2000;
    constexpr int OPEN = 850;
}

// Arm position struct
constexpr Arm::ArmPosition HomePosition = {
    ShoulderPositions::DOWN,
    ElbowPositions::DOWN,
    ClawPositions::OPEN};

constexpr Arm::ArmPosition DownPositionOpen = {
    ShoulderPositions::DOWN,
    ElbowPositions::DOWN,
    ClawPositions::OPEN};

constexpr Arm::ArmPosition DownPositionClosed = {
    ShoulderPositions::DOWN,
    ElbowPositions::DOWN,
    ClawPositions::CLOSED};

constexpr Arm::ArmPosition UpPositionOpen = {
    ShoulderPositions::UP,
    ElbowPositions::UP,
    ClawPositions::OPEN};

constexpr Arm::ArmPosition UpPositionClosed = {
    ShoulderPositions::UP,
    ElbowPositions::UP,
    ClawPositions::CLOSED};

// Tick Numbers
constexpr int TICKS_PER_180 = 3950;
constexpr int TICKS_PER_90 = TICKS_PER_180 / 2;
constexpr int TICKS_PER_45 = TICKS_PER_180 / 4;
constexpr int TICKS_PER_DEGREE = TICKS_PER_180 / 180;

int main()
{
    // Setup Drivetrain
    std::cout << "[INIT]" << " " << "WELCOME TO PROJECT-XBOT" << std::endl;
    std::cout << "Library versions:" << KIPR_VERSION << std::endl;
    DriveTrain DriveTrain(0, 1, 2, 3, 0, 1);

    DriveTrain.SetPerformance(1.0, 1.0, 0.9, 0.9);
    DriveTrain.SetLineTrackingThresholds(200, 200, 2000, 2000);

    // Setup Arm
    Arm Arm(0, 1, 2);
    Arm.SetPosition(UpPositionOpen);

    DriveTrain.DriveForward(750, 1500);
    DriveTrain.RotateRight(TICKS_PER_90, 1000);
    DriveTrain.DriveBackward(3000, 1500);
    DriveTrain.DriveLeftToLine(500);

    DriveTrain.DriveRight(1000, 1000);
    DriveTrain.DriveForward(1000, 1000);
    DriveTrain.DriveLeftToLine(500);

    // DriveTrain.DriveLeft(3500, 1500);
    // DriveTrain.DriveForwardToLine(500);
    // DriveTrain.DriveForwardToLine(500);

    // DriveTrain.DriveForward(2000, 1000);
    // DriveTrain.DriveRight(5500, 1500);

    return 0;
}
