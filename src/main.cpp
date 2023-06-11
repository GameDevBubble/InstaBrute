#include "Log/Log.h"
#include "browser/browser.h"
#include <string>
#include <fstream>
#include <iostream>

// Define the Program Name
std::string programName = "InstaBrute";

bool Debug = true;


void generateCombinations(const std::string& chars, int length, std::vector<std::string>& combinations, std::string& current, int& count) {
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

        // Generate combinations of length 1
        generateCombinations(lowercase + uppercase + numbers + specialChars, 1, combinations, currentCombination, combinationCount);

        // Generate combinations of length 2
        generateCombinations(lowercase + uppercase + numbers + specialChars, 2, combinations, currentCombination, combinationCount);

        // Generate combinations of length 3
        generateCombinations(lowercase + uppercase + numbers + specialChars, 3, combinations, currentCombination, combinationCount);

        // Generate combinations of length 4
        generateCombinations(lowercase + uppercase + numbers + specialChars, 4, combinations, currentCombination, combinationCount);

        generateCombinations(lowercase + uppercase + numbers + specialChars, 5, combinations, currentCombination, combinationCount);
        generateCombinations(lowercase + uppercase + numbers + specialChars, 6, combinations, currentCombination, combinationCount);
        generateCombinations(lowercase + uppercase + numbers + specialChars, 7, combinations, currentCombination, combinationCount);
        generateCombinations(lowercase + uppercase + numbers + specialChars, 8, combinations, currentCombination, combinationCount);
        generateCombinations(lowercase + uppercase + numbers + specialChars, 9, combinations, currentCombination, combinationCount);
        generateCombinations(lowercase + uppercase + numbers + specialChars, 10, combinations, currentCombination, combinationCount);

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

        return 0;
        // Add any other debug mode specific code here
        // ...
    } else {
        // Release mode: Add your code for the release version here
        // For example, you can display a message or perform alternative actions
        Log::Log(Log::LogLevel::INFO, "Release mode is active.");
        Log::Log(Log::LogLevel::INFO, "opening donation link");
        Browser::UrlRelated::openURL(url);
    }

    return 0;
}