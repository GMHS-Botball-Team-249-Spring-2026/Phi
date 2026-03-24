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
    std::cout << "Library versions: " << KIPR_VERSION << std::endl;
    DriveTrain DriveTrain(0, 1, 2, 3, 0, 1);

    DriveTrain.SetPerformance(1.0, 1.0, 1.00, 1.00);
    DriveTrain.SetLineTrackingThresholds(200, 200, 2000, 2000);

    // Setup Arm
    Arm Arm(0, 1, 2);
    Arm.SetPosition(UpPositionOpen);

    DriveTrain.DriveForward(750, 1500);
    DriveTrain.RotateRight(TICKS_PER_90, 1000);
    DriveTrain.DriveBackward(3000, 1500);

    // Change me
    DriveTrain.DriveForward(750, 1000);

    DriveTrain.StrafeLeftOnToLine(500);

    DriveTrain.StrafeRight(1550, 1000);
    DriveTrain.DriveForward(1500, 1000);
    DriveTrain.StrafeLeftOnToLine(500);

    DriveTrain.StrafeRight(1850, 1000);
    DriveTrain.DriveForwardToLine(500);
    DriveTrain.DriveBackward(150, 500);

    DriveTrain.RotateLeft(TICKS_PER_90, 1000);
    // DriveTrain.StrafeRight(25, 1000);
    DriveTrain.DriveForwardToLine(500);

    DriveTrain.DriveForward(1450, 1000);
    // DriveTrain.StrafeRight(1400, 1000);

    DriveTrain.StrafeLeft(2750, 1500);

    // Pushing Blue Poms
    DriveTrain.StrafeRight(850, 1000);
    DriveTrain.DriveForward(775, 1000);
    // DriveTrain.SquareWithLine(100);
    DriveTrain.DriveForward(2000, 1000);
    DriveTrain.StrafeLeft(500, 1500);

    DriveTrain.DriveBackwardToLine(1000);
    DriveTrain.DriveBackward(500, 1500);
    DriveTrain.SquareWithLine(250);
    DriveTrain.DriveBackward(225, 1000);
    DriveTrain.StrafeRight(2500, 1500);

    DriveTrain.DriveForward(750, 1000);
    DriveTrain.DriveBackward(750, 1000);

    DriveTrain.RotateLeft(TICKS_PER_90 / 3, 1000);
    DriveTrain.RotateRight(TICKS_PER_90 / 3, 1000);

    DriveTrain.DriveForward(400, 1500);

    DriveTrain.RotateRight(TICKS_PER_90 / 3, 1000);
    DriveTrain.RotateLeft(TICKS_PER_90 / 3, 1000);

    // DriveTrain.DriveBackward(175, 1500);

    DriveTrain.SquareWithLine(250);
    DriveTrain.DriveBackward(225, 1000);
    DriveTrain.StrafeRight(2750, 1500);

    DriveTrain.StrafeLeft(100, 1000);
    DriveTrain.SquareWithLine(250);
    DriveTrain.DriveForward(350, 1000);
    DriveTrain.DriveBackwardToLine(500);
    DriveTrain.DriveBackward(600, 1000);
    DriveTrain.StrafeRight(5250, 1500);

    DriveTrain.DriveBackward(650, 1000);

    DriveTrain.RotateLeft(TICKS_PER_45, 1000);
    DriveTrain.DriveBackward(350, 1000);
    DriveTrain.RotateLeft(TICKS_PER_45, 1000);
    DriveTrain.DriveBackward(150, 1000);

    DriveTrain.StrafeRightOnToLine(500);

    DriveTrain.StrafeRight(250, 1000);
    Arm.SetPosition(DownPositionOpen);

    // DriveTrain.DriveBackward(550, 1500);

    DriveTrain.DriveForward(1400, 1500);
    DriveTrain.DriveForwardToLine(500);
    // DriveTrain.DriveForwardLineTracking(1500, 500);

    Arm.SetPosition(DownPositionClosed);
    msleep(1000);
    Arm.SetPosition(UpPositionClosed);

    DriveTrain.StrafeLeft(500, 1000);
    DriveTrain.DriveBackward(750, 1500);
    DriveTrain.StrafeRight(750, 1000);
    DriveTrain.DriveForward(2000, 1500);
    DriveTrain.StrafeLeftOnToLine(500);
    DriveTrain.DriveBackward(750, 1500);
    DriveTrain.DriveForwardToLine(500);

    DriveTrain.StrafeLeft(500, 1000);
    DriveTrain.DriveForward(7500, 1500);
    DriveTrain.StrafeLeft(4000, 1500);

    Arm.SetPosition(DownPositionClosed);
    msleep(1000);
    Arm.SetPosition(DownPositionOpen);
    msleep(1000);
    Arm.SetPosition(UpPositionOpen);

    DriveTrain.StrafeRight(750, 1500);
    DriveTrain.RotateRight(TICKS_PER_90, 1000);
    DriveTrain.DriveForwardToLine(500);
    DriveTrain.DriveBackward(50, 1500);
    DriveTrain.StrafeRightToLine(500);
    DriveTrain.SquareWithLine(250);

    Arm.SetPosition(UpPositionOpen);
    return 0;
}
