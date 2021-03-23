#pragma once

#include "BaseLogger.h"

using namespace System::IO;

ref class FileLogger :
	public BaseLogger
{
private:
	// The log file path.
	String^ logFilePath;

public:
	// Represents a file logger.
	FileLogger();

	// Logs the given message.
    //   message: The message to log.
	void Log(String^ message) override;
};

