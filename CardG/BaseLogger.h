#pragma once

using namespace System;

ref class BaseLogger abstract
{
public:
	// Logs the given message.
	//   message: The message to log.
	virtual void Log(String^ message) = 0;
};

