#include "LcsAlg.hpp"
int main() {
    LcsAlg la;

    std::cout << "\nPart 1" << std::endl; 
    std::vector<std::string> twoStrings = la.TwoStringsFromFile("twoStrings.txt");
    std::cout << "length x : " << twoStrings.at(0).length() << std::endl;
    std::cout << "length y : " << twoStrings.at(1).length() << std::endl;
    std::string lcs = la.GetLCS(twoStrings.at(0), twoStrings.at(1));
    std::cout << "length lcs : " << lcs.length() << std::endl;
    std::cout << "lcs : " << lcs << std::endl;

    std::cout << "\nPart 2" << std::endl;
    std::vector<std::string> multiStrings = la.MultiStringsFromFile("multiStrings.txt");
    std::vector<std::vector<char>> matrix = la.GetSimilarityMatrix(multiStrings);
    //print similarity matrix
    for (std::vector<char> v : matrix) {
        for (char c : v) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}