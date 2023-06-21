//
// Created by julian on 11.06.23.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

// Values in decimal
int first = 32, last = 126, characters = 13, hashval = 1207;

vector<vector<int>> combinations;

#ifndef INSTABRUTE_BRUTEFORCE_H
#define INSTABRUTE_BRUTEFORCE_H

namespace BruteForce {

    class BruteForce {
    private:
        void brute(int n, int it, vector<int>& values) {
            if (n == 0) {
                int sum = 0;

                // Sum up recent values
                for (int j = 0; j < characters; ++j) {
                    sum += values[j];
                }
                // Save values if matching to hash
                if (sum == hashval) {
                    combinations.push_back(values);
                }
            } else {
                for (int i = first; i <= last; ++i) {
                    values[it] = i;
                    brute(n - 1, it + 1, values);
                }
            }
        }

    public:
        void generateCombinations() {
            vector<int> values(characters);
            brute(characters, 0, values);
        }

        void printToFile() {
            ofstream outputFile("fileContent.brute");
            if (!outputFile) {
                cerr << "Failed to open output file." << endl;
                return;
            }
            
            outputFile << "\n\nFound " << combinations.size() << " combinations." << endl;
            for (const auto& combo : combinations) {
                for (int i = 0; i < characters; ++i) {
                    outputFile << static_cast<char>(combo[i]) << " ";
                }
                outputFile << "\r\n";
            }

            outputFile.close();
        }
    };

} 

#endif // INSTABRUTE_BRUTEFORCE_H
