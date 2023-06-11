//
// Created by julian on 11.06.23.
//

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
using namespace std::chrono;

//values in decimal
int first = 32, last = 126, characters = 13, hashval = 1207;

vector<vector<int>> combinations;

#ifndef INSTABRUTE_BRUTEFORCE_H
#define INSTABRUTE_BRUTEFORCE_H

namespace BruteForce {

    class BruteForce {
        void brute(int n, int it, vector<int> values) {
            if (n == 0) {
                int sum = 0;

                //sum up recent values
                for (int j = 0; j < characters; ++j) {
                    sum += values[j];
                }
                //save values if matching to hash
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


        void printToFile(){
            freopen("fileContent.brute", "w", stdout);
            cout << "\n\nFound " << combinations.size() << " combinations." << endl;
            int counter = 0;
            for (auto combo = combinations.begin(); combo != combinations.end(); ++combo){
                for (int i = 0; i <  characters; ++i) {
                    cout << (char) combinations.at(counter).at(i) << " ";
                }
                cout<< "\r\n";
                counter++;
            }
        }
    };

} // BruteForce

#endif //INSTABRUTE_BRUTEFORCE_H
