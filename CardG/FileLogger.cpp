#include "FileLogger.h"

FileLogger::FileLogger()
{
    this->logFilePath = "Card-G.log";
}

void FileLogger::Log(String^ message)
{
    StreamWriter^ streamWriter = gcnew StreamWriter(this->logFilePath, true);
    // Log the current date and time.
    streamWriter->Write(DateTime::Now);
    streamWriter->WriteLine(": ");
    // Log the message.
    streamWriter->WriteLine(message);
    streamWriter->Close();
}
