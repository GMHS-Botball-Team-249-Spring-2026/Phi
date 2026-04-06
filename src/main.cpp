#include "Arm.hpp"
#include "DriveTrain.hpp"
#include <iostream>
#include <kipr/wombat.h>

// Constants for arm positions
namespace ShoulderPositions {
constexpr int DOWN = 1900;
constexpr int UP = 830;
} // namespace ShoulderPositions

namespace ElbowPositions {
constexpr int DOWN = 0;
constexpr int UP = 0;
} // namespace ElbowPositions

namespace ClawPositions {
constexpr int CLOSED = 2000;
constexpr int OPEN = 850;
} // namespace ClawPositions

// Arm position struct
constexpr Arm::ArmPosition HomePosition = {
    ShoulderPositions::DOWN, ElbowPositions::DOWN, ClawPositions::OPEN};

constexpr Arm::ArmPosition DownPositionOpen = {
    ShoulderPositions::DOWN, ElbowPositions::DOWN, ClawPositions::OPEN};

constexpr Arm::ArmPosition DownPositionClosed = {
    ShoulderPositions::DOWN, ElbowPositions::DOWN, ClawPositions::CLOSED};

constexpr Arm::ArmPosition UpPositionOpen = {
    ShoulderPositions::UP, ElbowPositions::UP, ClawPositions::OPEN};

constexpr Arm::ArmPosition UpPositionClosed = {
    ShoulderPositions::UP, ElbowPositions::UP, ClawPositions::CLOSED};

// Tick Numbers
constexpr int TICKS_PER_180 = 3950;
constexpr int TICKS_PER_90 = TICKS_PER_180 / 2;
constexpr int TICKS_PER_45 = TICKS_PER_180 / 4;
constexpr int TICKS_PER_DEGREE = TICKS_PER_180 / 180;

int main() {
  // Setup Drivetrain
  std::cout << "[INIT]" << " " << "WELCOME TO PROJECT-XBOT" << std::endl;
  std::cout << "Library versions: " << KIPR_VERSION << std::endl;
  DriveTrain DriveTrain(0, 1, 2, 3, 0, 1);

  // Set performance and line tracking thresholds
  DriveTrain.SetPerformance(1.0, 1.0, 1.00, 1.00);
  DriveTrain.SetLineTrackingThresholds(200, 200, 2000, 2000);

  // Setup Arm
  Arm Arm(0, 1, 2);
  // Set arm position to open
  Arm.SetPosition(UpPositionOpen);

  // Rotate & Drive into side
  DriveTrain.DriveForward(750, 1500);
  DriveTrain.RotateRight(TICKS_PER_90, 1000);
  DriveTrain.DriveBackward(3000, 1500);

  // Push startbox poms
  DriveTrain.DriveForward(750, 1000);
  DriveTrain.StrafeLeftOnToLine(500);
  DriveTrain.StrafeRight(1550, 1000);
  DriveTrain.DriveForward(1500, 1000);
  DriveTrain.StrafeLeftOnToLine(500);
  DriveTrain.StrafeRight(1850, 1000);
  DriveTrain.DriveForwardToLine(500);
  DriveTrain.DriveBackward(60, 500);

  // Rotate and Drive left to push poms
  DriveTrain.RotateLeft(TICKS_PER_90, 1000);
  DriveTrain.DriveForwardToLine(500);
  DriveTrain.DriveForward(1450, 1000);
  DriveTrain.StrafeLeft(2750, 1500);

  // Get blue poms
  DriveTrain.StrafeRight(900, 1000);
  DriveTrain.DriveForward(775, 1000);
  DriveTrain.DriveForward(2000, 1000);
  // DriveTrain.StrafeLeft(500, 1500);

  DriveTrain.DriveBackwardToLine(1000);
  DriveTrain.DriveBackward(500, 1500);
  DriveTrain.SquareWithLine(250);
  DriveTrain.DriveBackward(225, 1000);

  // Start pushing my orange poms
  DriveTrain.StrafeRight(2500, 1500);

  DriveTrain.DriveForward(750, 1000);
  DriveTrain.DriveBackward(750, 1000);

  // Move the poms into more of a center
  DriveTrain.RotateLeft(TICKS_PER_90 / 3, 1000);
  DriveTrain.RotateRight(TICKS_PER_90 / 3, 1000);

  DriveTrain.DriveForward(400, 1500);

  DriveTrain.RotateRight(TICKS_PER_90 / 3, 1000);
  DriveTrain.RotateLeft(TICKS_PER_90 / 3, 1000);

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

  // Move poms to be strafed into another box
  DriveTrain.RotateLeft(TICKS_PER_45, 1000);
  DriveTrain.DriveBackward(400, 1000);
  DriveTrain.RotateLeft(TICKS_PER_45, 1000);
  DriveTrain.DriveBackward(150, 1000);
  DriveTrain.StrafeRightOnToLine(500);
  // DriveTrain.StrafeRight(250, 1000);

  // Get traffic cone
  Arm.SetPosition(DownPositionOpen);
  DriveTrain.DriveForwardLineTracking(1400, 1500);
  DriveTrain.DriveForwardToLine(500);
  Arm.SetPosition(DownPositionClosed);
  msleep(1000);
  Arm.SetPosition(UpPositionClosed);

  DriveTrain.DriveBackward(500, 1500);
  DriveTrain.StrafeRight(600, 1500);
  DriveTrain.DriveForward(2000, 1500);
  DriveTrain.StrafeLeftOnToLine(1500);
  DriveTrain.StrafeLeft(2500, 1500);
  DriveTrain.DriveForward(7000, 1500);
  DriveTrain.StrafeLeft(2000, 1500);
  DriveTrain.DriveForward(2500, 1500);
  DriveTrain.StrafeRightOnToLine(500);
  DriveTrain.DriveDiagonalBackwardLeft(3000, 1500);

  // Drop traffic cone
  Arm.SetPosition(DownPositionClosed);
  Arm.SetPosition(DownPositionOpen);
  msleep(1000);
  Arm.SetPosition(UpPositionOpen);
  return 0;
}
