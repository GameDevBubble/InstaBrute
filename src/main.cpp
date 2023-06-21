#include "Log/Log.h"
#include "browser/browser.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

// Define the Program Name
std::string programName = "InstaBrute";

bool Debug = true;

void generateCombinations(const std::string& chars, int length, std::vector<std::string>& combinations, std::string current, int& count) {
    if (length == 0) {
        combinations.push_back(current);
        std::cout << "\rGenerated Combination: " << "combination: " << current << std::flush;
        ++count;
        return;
    }

    for (char c : chars) {
        current += c;
        generateCombinations(chars, length - 1, combinations, current, count);
        current.pop_back();
    }
}

int main() {
    // Log some messages at different log levels
    Log::Log(Log::LogLevel::INFO, "This is an informational message");

    std::string url = "https://www.paypal.me/GameDevBubble";

    if (Debug) {
        // Debug mode: Open URL in the default browser and log as debug version
        Log::Log(Log::LogLevel::DEBUG, "opening donation page");
        Browser::UrlRelated::openURL(url);
        Log::Log(Log::LogLevel::DEBUG, "opened donation link");

        std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
        std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string numbers = "0123456789";
        std::string specialChars = "!@#$%^&*()";

        std::vector<std::string> combinations;
        std::string currentCombination;
        int combinationCount = 0;

        // Generate combinations of different lengths
        for (int length = 1; length <= 10; ++length) {
            generateCombinations(lowercase + uppercase + numbers + specialChars, length, combinations, "", combinationCount);
        }

        // Open the file to save combinations
        std::ofstream outputFile("combinations.txt");
        if (!outputFile) {
            std::cerr << "Failed to open output file." << std::endl;
            return 1;
        }

        // Save all generated combinations to the file
        for (const std::string& combination : combinations) {
            outputFile << combination << std::endl;
        }

        outputFile.close();
        std::cout << "\nCombinations saved to combinations.txt" << std::endl;
        std::cout << "Total Combinations Generated: " << combinationCount << std::endl;

        // Add any other debug mode specific code here
        // ...

        return 0;
    } else {
        // Release mode: Add your code for the release version here
        // For example, you can display a message or perform alternative actions
        Log::Log(Log::LogLevel::INFO, "Release mode is active.");
        Log::Log(Log::LogLevel::INFO, "opening donation link");
        Browser::UrlRelated::openURL(url);
    }

    return 0;
}
