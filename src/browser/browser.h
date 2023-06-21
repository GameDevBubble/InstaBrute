#ifndef INSTABRUTE_BROWSER_H
#define INSTABRUTE_BROWSER_H

#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <wininet.h>
#else
#include <unistd.h>
#endif

namespace Browser {
    namespace UrlRelated {
        void openURL(const std::string& url) {
#ifdef _WIN32
            std::string command = "start " + url; // Command to open URL in default browser on Windows
#else
            std::string command = "xdg-open " + url; // Command to open URL in default browser on Linux
#endif
            system(command.c_str());
        }
    }

    std::string scrapeInstagramLoginPage(const std::string& username, const std::string& password) {
        std::string loginUrl = "https://www.instagram.com/accounts/login/";
        std::string response;

#ifdef _WIN32
        HINTERNET hInternet = InternetOpenA("Instagram Scraper", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
        if (hInternet) {
            HINTERNET hConnect = InternetOpenUrlA(hInternet, loginUrl.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
            if (hConnect) {
                DWORD bytesRead = 0;
                CHAR buffer[4096];

                // Read the response into a buffer
                while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
                    response.append(buffer, bytesRead);
                }

                // Here you can parse the response to extract the error code or perform any other actions

                // Example: Check if the response contains an error message
                if (response.find("error message") != std::string::npos) {
                    // Extract the error code from the response
                    // You can use string manipulation or a library like Boost or regex for more complex parsing
                    // For simplicity, let's assume the error code is between "<error>" and "</error>"
                    size_t errorStart = response.find("<error>");
                    size_t errorEnd = response.find("</error>");
                    std::string errorCode = response.substr(errorStart + 7, errorEnd - errorStart - 7);

                    // Clean up
                    InternetCloseHandle(hConnect);
                    InternetCloseHandle(hInternet);

                    // Return the error code
                    return errorCode;
                }

                // Clean up
                InternetCloseHandle(hConnect);
            } else {
                std::cerr << "Failed to open URL: " << GetLastError() << std::endl;
            }

            // Clean up
            InternetCloseHandle(hInternet);
        } else {
            std::cerr << "Failed to initialize WinINet" << std::endl;
        }
#else
        // Code for non-Windows platforms (e.g., Linux) if needed
        // Add your implementation here
#endif

        return "";  // Return an empty string if no error code was found
    }
}

#endif // INSTABRUTE_BROWSER_H
