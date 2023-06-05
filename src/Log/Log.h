//
// Created by julian on 05.06.23.
//

#ifndef INSTABRUTE_LOG_H
#define INSTABRUTE_LOG_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

extern std::string programName;  // Declaration of the programName variable

namespace Log {
    enum class LogLevel {
        EMERGENCY,
        ALERT,
        CRITICAL,
        ERROR,
        WARNING,
        NOTICE,
        INFORMATIONAL,
        DEBUG,
        VERBOSE,
        FINEST,
        OFF,
        INFO
    };

    void saveStringToFile(const std::string& fileName, const std::string& content) {
        std::ofstream outputFile(fileName, std::ios::app); // Open the file in append mode
        if (outputFile.is_open()) {
            outputFile << content << std::endl; // Append a new line after the content
            outputFile.close();
        } else {
            std::cout << "Unable to open file " << fileName << std::endl;
        }
    }

    void Log(LogLevel level, const std::string& message, bool writeToLogFile = true, bool showTimestamp = false) {
        std::string LogLevelString;
        std::string LogLevelColorCode;
        std::string ResetColorCode = "\033[0m";

        switch (level) {
            case LogLevel::EMERGENCY:
                LogLevelString = "EMERGENCY";
                LogLevelColorCode = "\033[1;35m";
                break;
            case LogLevel::ALERT:
                LogLevelString = "ALERT    ";
                LogLevelColorCode = "\033[1;36m";
                break;
            case LogLevel::CRITICAL:
                LogLevelString = "CRITICAL ";
                LogLevelColorCode = "\033[1;31m";
                break;
            case LogLevel::ERROR:
                LogLevelString = "ERROR    ";
                LogLevelColorCode = "\033[1;31m";
                break;
            case LogLevel::WARNING:
                LogLevelString = "WARNING  ";
                LogLevelColorCode = "\033[1;33m";
                break;
            case LogLevel::NOTICE:
                LogLevelString = "NOTICE   ";
                LogLevelColorCode = "\033[1;37m";
                break;
            case LogLevel::INFORMATIONAL:
                LogLevelString = "INFO     ";
                LogLevelColorCode = "\033[1;32m";
                break;
            case LogLevel::DEBUG:
                LogLevelString = "DEBUG    ";
                LogLevelColorCode = "\033[1;34m";
                break;
            case LogLevel::VERBOSE:
                LogLevelString = "VERBOSE  ";
                LogLevelColorCode = "\033[1;36m";
                break;
            case LogLevel::FINEST:
                LogLevelString = "FINEST   ";
                LogLevelColorCode = "\033[1;35m";
                break;
            case LogLevel::OFF:
                return; // No logging required
            case LogLevel::INFO:
                LogLevelString = "INFO     ";
                LogLevelColorCode = "\033[1;32m";
                break;
        }

        std::string LogMessage;
        std::string LogMessageToSave;

        std::time_t now = std::time(nullptr);
        std::tm* localtime = std::localtime(&now);
        char timestamp[20];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime);

        LogMessage += LogLevelColorCode + "[" + programName + "::" + LogLevelString + "] --> " + message + ResetColorCode;
        LogMessageToSave += "[" + programName + "::" + LogLevelString + "] --> " + message + " --> " + std::string(timestamp);
        saveStringToFile(programName + ".log", LogMessageToSave);

        std::cout << LogMessage << std::endl;
    }
}

#endif //INSTABRUTE_LOG_H