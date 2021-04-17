#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::string> readTwoStringsFromFile(std::string fileName) {
    std::vector<std::string> s;
    std::ifstream inFile(fileName);  
    if (inFile.is_open()) {
        std::string line;

        //read first string
        if (inFile >> line) {
            std::stringstream ss(line);
            ss >> line;
            s.push_back(line);
        }

        //read second string
        if (inFile >> line) {
            std::stringstream ss(line);
            ss >> line;
            s.push_back(line);
        }

        inFile.close();
    } else {
        std::cout << "Cannot open file : " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }
    return s;
}
int getMax(int a, int b) {
    return (a > b) ? a : b;
}
std::string getLCS(std::string x, std::string y) {
    //initialize lcs matrix
    int m = x.length() + 1;
    int n = y.length() + 1;
    int c[m][n] = {};

    //fill matrix
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = getMax(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    //intialize lcs
    int i = x.length();
    int j = y.length();
    int index = c[i][j];
    char lcs[index + 1];
    lcs[index] = '\0';
    
    //traverse through matrix to create lcs
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcs[index - 1] = x[i - 1];
            index--;
            i--;
            j--;
        } else if (c[i - 1][j] > c[i][j - 1]) {
            i--;
        } else {
            j--;
        } 
    }
    return lcs;
}

int main() {
    std::vector<std::string> s = readTwoStringsFromFile("twoStrings.txt");
    std::cout << getLCS(s[0], s[1]) << std::endl;

    return 0;
};