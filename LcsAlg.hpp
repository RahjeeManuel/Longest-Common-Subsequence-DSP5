#ifndef LCSALG_HPP
#define LCSALG_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
class LcsAlg {
    private:
        std::string stringA;
        std::string stringB;
        int GetMax(int a, int b);
    public:
        LcsAlg();
        void TwoStringsFromFile(std::string fileName);
        std::string GetStringA();
        std::string GetStringB();
        std::string GetLCS();
};
#endif