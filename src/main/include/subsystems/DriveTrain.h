#pragma once

#include <frc/commands/Subsystem.h>
#include "RobotMap.h"
#include <iostream>
#include <frc/WPILib.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Victor.h>
#include <frc/Joystick.h>
#include <ctre/phoenix.h>
#include <frc/DoubleSolenoid.h>

class DriveTrain : public frc::Subsystem {
private:
	// frc::Victor mFrontLeftController;
	// frc::Victor mRearLeftController;
	// frc::Victor mFrontRightController;
	// frc::Victor mRearRightController;

	WPI_TalonSRX mFrontLeftController;
	WPI_TalonSRX mRearLeftController;
	WPI_TalonSRX mFrontRightController;
	WPI_TalonSRX mRearRightController;

 	frc::SpeedControllerGroup mLeftSide{mFrontLeftController, mRearLeftController};
 	frc::SpeedControllerGroup mRightSide{mFrontRightController, mRearRightController};

 	frc::DifferentialDrive mDrive{mLeftSide, mRightSide};

	Faults _faults;
	int _loops = 0;
	

public:
 	DriveTrain();
	~DriveTrain();

    void InitDefaultCommand() override;
	// void DRCDrive(double ySpeed,double xSpeed);
	void DRCDrive(double move,double rotate);
	void MotionMagicDrive();
	bool isMotionMagicDriveFinished();
	// frc::DoubleSolenoid mSolenoid{6, 7};
	// void SRXOutput();
};