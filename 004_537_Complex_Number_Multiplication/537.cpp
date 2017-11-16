#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
// Time complexity
// std::sort
//      average case linearithmic (nlogn) time complexity.
// std:: stable_sort
//      quasilinear worst case time complexity (n log^2 n)
// substr
// substr(0, found); 从 0 到 found 之前
// substr(found + 1); 从 found 之后一位到最后
class Solution {
  public:
    void reslove(string input, int &Re, int &Im) {
        size_t found0 = input.find("+");
        string ReString = input.substr(0, found0);
        Re = stoi(ReString);
        string ImString = input.substr(found0 + 1);
        ImString = ImString.substr(0, (ImString.size() - 1) );
        Im = stoi(ImString);
    }
    string complexNumberMultiply(string a, string b) {
        int aRe, aIm, bRe, bIm;
        reslove(a, aRe, aIm);
        reslove(b, bRe, bIm);
        int xRe = aRe * bRe - aIm * bIm;
        int xIm = aIm * bRe + aRe * bIm;
        string Result = to_string(xRe) + "+" + to_string(xIm) + "i";
        return Result;
    }
};

class StreamSolution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
        return ans.str();
    }
};

int main(int argc, char const *argv[]) {
    StreamSolution solution;
    // string test = "-3";
    // int x = stoi(test);
    // cout << "x:" << x << endl;
    // cout << solution.complexNumberMultiply("1+-1i", "1+-1i");
    int a,b,c,d;
    char e,f;
    string g;
    // By default >> skips whitespace
    string test = "1 2 3 4 i j k?3";
    stringstream aa(test);
    aa >> a >> b >> c >> d >> e >> f >> g;
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;
    cout << "d:" << d << endl;
    cout << "e:" << e << endl;
    cout << "f:" << f << endl;
    cout << "g:" << g << endl;
    return 0;
}