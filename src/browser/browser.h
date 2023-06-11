//
// Created by julian on 05.06.23.
//

#ifndef INSTABRUTE_BROWSER_H
#define INSTABRUTE_BROWSER_H

#include <iostream>
#include "../Log/Log.h"
#include <boost/asio.hpp>
#include <cstdlib>

extern bool Debug;

namespace Browser {
    namespace UrlRelated {
        void openURL(const std::string& url) {
#ifdef _WIN32
            std::string command = "start " + url; // Command to open URL in default browser on Windows
            if (Debug) {
                Log::Log(Log::LogLevel::DEBUG, "Debug version");
                system(command.c_str());
            } else {
                Log::Log(Log::LogLevel::INFO, "Release version");
                // Add your code for release version here (if any)
            }
#else
            std::string command = "xdg-open " + url; // Command to open URL in default browser on Linux
            if (Debug) {
                Log::Log(Log::LogLevel::DEBUG, "Debug version");
                system(command.c_str());
            } else {
                Log::Log(Log::LogLevel::INFO, "Release version");
                system(command.c_str());
            }
#endif
        }
    }
}

#endif //INSTABRUTE_BROWSER_H