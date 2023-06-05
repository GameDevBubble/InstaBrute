#include "Log/Log.h"

// extern std::string programName; // Declaration of the programName variable
std::string programName = "InstaBrute";  // Definition of the programName variable

int main() {

    // Log some messages at different log levels
    Log::Log(Log::LogLevel::INFO, "This is an informational message");
    Log::Log(Log::LogLevel::WARNING, "This is a warning message");
    Log::Log(Log::LogLevel::ERROR, "This is an error message");

    return 0;
}
