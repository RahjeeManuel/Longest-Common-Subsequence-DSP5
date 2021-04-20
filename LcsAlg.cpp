#include "LcsAlg.hpp"
int LcsAlg::GetMax(int a, int b) {
    return (a > b) ? a : b;
}
LcsAlg::LcsAlg() {
    this->stringA = "";
    this->stringB = "";
}
void LcsAlg::TwoStringsFromFile(std::string fileName) {
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string line;
        //read first string
        if (inFile >> line) {
            std::stringstream ss(line);
            ss >> stringA;
        }
        //read second string
        if (inFile >> line) {
            std::stringstream ss(line);
            ss >> stringB;
        }
        inFile.close();
    } else {
        std::cout << "Cannot open file : " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::string LcsAlg::GetStringA() {
    return stringA;
}
std::string LcsAlg::GetStringB() {
    return stringB;
}
std::string LcsAlg::GetLCS() {
    //initialize matrix
    int m = stringA.length() + 1;
    int n = stringB.length() + 1;
    int c[m][n];
    for (int i = 0; i < m; i++) {
        c[i][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[0][i] = 0;
    }
    //fill matrix
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (stringA[i - 1] == stringB[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = GetMax(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    //intialize lcs array
    int i = stringA.length();
    int j = stringB.length();
    int index = c[i][j];
    char lcs[index + 1];
    lcs[index] = '\0';
    
    //traverse through matrix to create lcs array
    while (i > 0 && j > 0) {
        if (stringA[i - 1] == stringB[j - 1]) {
            lcs[index - 1] = stringA[i - 1];
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