#pragma once

#include "BaseLogger.h"

using namespace System::Collections::Generic;

ref class BaseGameEngine
{
private:
	// The attached loggers.
	List<BaseLogger^>^ loggers;

public:
	// Represents a base game engine.
	BaseGameEngine();

	// Attaches the given logger.
	//   logger: The logger to attach.
	void attach(BaseLogger^ logger);
	
	// Detaches the given logger.
	//   logger: The logger to detach.
	void detach(BaseLogger^ logger);
	
	// Notifies all the attached loggers.
	//   message: The message to send to all the attached loggers.
	void notify(String^ message);
};

