#include "LcsAlg.hpp"

int main() {
    LcsAlg la;

    std::vector<std::string> twoStrings = la.TwoStringsFromFile("twoStrings.txt");
    std::string x = twoStrings.at(0);
    std::string y = twoStrings.at(1);
    std::string lcs = la.GetLCS(x, y);
    std::cout << "length x : " << x.length() << std::endl;
    std::cout << "length y : " << y.length() << std::endl;
    std::cout << "length lcs : " << lcs.length() << std::endl;
    std::cout << "lcs : " << lcs << std::endl;

    std::vector<std::string> multiStrings = la.MultiStringsFromFile("multiStrings.txt");
    std::vector<std::vector<char>> matrix = la.GetSimilarityMatrix(multiStrings);
    for (std::vector<char> v : matrix) {
        for (char c : v) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}