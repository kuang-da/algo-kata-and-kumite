#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    string reverseOneWord(string s) {
        string result = "";
        for (int i = s.size() - 1; i >= 0; i--)
            result += s.at(i);
        return result;
    }
    string reverseWords(string s) {
        stringstream ss;
        ss << s;
        string result = "";
        string temp = "";
        while (ss >> temp) {
            result += reverseOneWord(temp) + " ";
        }
        result = result.substr(0, result.size() - 1);
        return result;
    }
};
// reverse is a build in function in c++ STL
class Solution1 {
public:
    string reverseWords(string s) {
        stringstream ss;
        ss<< s;
        string result = "";
        string temp = "";
        while(ss>>temp){
            reverse(temp.begin(), temp.end());
            result += temp + " ";
        }
        result = result.substr(0, result.size()-1);
        return result;
    }
};

int main(int argc, char const *argv[]) {
    string test = "abc defg";
    reverse(test.begin(), test.end());
    cout << test << endl;
    return 0;
}