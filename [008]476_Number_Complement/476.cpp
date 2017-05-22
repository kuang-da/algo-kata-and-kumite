#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <bitset>
using namespace std;
// The range of int: 2^32 = 4294967296
// -2147483648 <= int x <= 2147483647
    // int y = 2147483647;
    // y++;
    // y = -2147483648;
// use mask to turn the out of range bits on 1
// so that we can use invert
// how to decide the mask?
// -> to turn bits on, we need to cover the bits with 1. 
// So the mask should be like 111111000
// how to decide the bits of 1?
// I want to use 1 to cover the 0 parts -> & = 0; | = 1
// I want to use 0 to cover the binarty parts -> & = 0; | = 1;
// -> while(mask & binary) mask << 1;
class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while(mask & num) mask <<= 1;
        return ~(mask | num);
    }
};
// Could also think about XOR method
int main(int argc, char const *argv[]) {
    // int num = -5;
    // bitset<32> bs = num;
    // for (int i = 31; i >= 0; i--) {
    //     cout << bs[i];
    // }
    // int mask = ~0;
    // cout << "\nmask" << mask << endl;

    // while (num & mask) {
    //     mask <<= 1;
    //     cout << "mask" << mask << endl;
    // }
    // cout << dddd;

    int y = 2147483647;
    y++;
    cout << "y:" << y << endl;
    return 0;
}