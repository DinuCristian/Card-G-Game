#include "BaseGameEngine.h"

BaseGameEngine::BaseGameEngine()
{
	this->loggers = gcnew List<BaseLogger^>();
}

void BaseGameEngine::attach(BaseLogger^ logger)
{
	this->loggers->Add(logger);
}

void BaseGameEngine::detach(BaseLogger^ logger)
{
	this->loggers->Remove(logger);
}

void BaseGameEngine::notify(String^ message)
{
	// Loop through all the attached loggers and notify each of them.
	for (int i = 0; i < this->loggers->Count; i++)
	{
		this->loggers[i]->Log(message);
	}
}
