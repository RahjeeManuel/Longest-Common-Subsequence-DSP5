#ifndef LCSALG_HPP
#define LCSALG_HPP
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
class LcsAlg {
    private:
        double GetMax(double a, double b);
        double GetMin(double a, double b);
        char GetSimilarity(std::string a, std::string b);   //returns char based on string similarity
    public:
        LcsAlg();
        std::vector<std::string> TwoStringsFromFile(std::string fileName);  //returns a string vector from twostrings file
        std::vector<std::string> MultiStringsFromFile(std::string fileName);    //returns a string vector from multistrings file
        std::string GetLCS(std::string a, std::string b);
        std::vector<std::vector<char>> GetSimilarityMatrix(std::vector<std::string> s);
};
#endif