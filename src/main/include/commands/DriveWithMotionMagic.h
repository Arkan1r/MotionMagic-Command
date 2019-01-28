#pragma once

#include <frc/commands/Command.h>

class DriveWithMotionMagic : public frc::Command {
public:
	DriveWithMotionMagic();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	bool start_mp = true;
};