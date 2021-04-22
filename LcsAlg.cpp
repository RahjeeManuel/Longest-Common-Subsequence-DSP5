#include "LcsAlg.hpp"
double LcsAlg::GetMax(double a, double b) {
    return a > b ? a : b;
}
double LcsAlg::GetMin(double a, double b) {
    return a < b ? a : b;
}
char LcsAlg::GetSimilarity(std::string a, std::string b) {
    std::string lcs = GetLCS(a, b);
    double min = GetMin(a.length(), b.length());
    double max = GetMax(a.length(), b.length());
    if (min / max >= 0.9 && lcs.length() / min >= 0.9) {
        return 'H';
    } else if (min / max >= 0.8 && lcs.length() / min >= 0.8) {
        return 'M';
    } else if (min / max >= 0.6 && lcs.length() / min >= 0.5) {
        return 'L';
    } else {
        return 'D';
    }
}

LcsAlg::LcsAlg() { 
}
std::vector<std::string> LcsAlg::TwoStringsFromFile(std::string fileName) {
    std::vector<std::string> s;
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string line;
        if (std::getline(inFile, line)) {
            std::stringstream ss(line);
            ss >> line;
            s.push_back(line);
        }
        if (std::getline(inFile, line)) {
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
std::vector<std::string> LcsAlg::MultiStringsFromFile(std::string fileName) {
    std::vector<std::string> s;
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string line;
        if (std::getline(inFile, line)) {
            int numStrings = 0;
            std::stringstream ss(line);
            ss >> numStrings;
            while(numStrings > 0 && std::getline(inFile, line)) {
                std::stringstream ss(line);
                ss >> line;
                s.push_back(line);
                numStrings--;
            }
        }
        inFile.close();
    } else {
        std::cout << "Cannot open file : " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }
    return s;
}
std::string LcsAlg::GetLCS(std::string a, std::string b) {
    int m = a.length() + 1;
    int n = b.length() + 1;
    int c[m][n];
    for (int i = 0; i < m; i++) {
        c[i][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[0][i] = 0;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = GetMax(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    int i = a.length();
    int j = b.length();
    int index = c[i][j];
    char lcs[index + 1];
    lcs[index] = '\0';
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs[index - 1] = a[i - 1];
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
std::vector<std::vector<char>> LcsAlg::GetSimilarityMatrix(std::vector<std::string> s) {
    std::vector<std::vector<char>> c;
    for (int i = 0; i < s.size(); i++) {
        std::vector<char> v;
        for (int j = 0; j < s.size(); j++) {
            v.push_back('-');
        }
        c.push_back(v);
    }
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            c.at(i).at(j) = GetSimilarity(s.at(i), s.at(j));
        }  
    }
    return c;
}