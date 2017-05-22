#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if( r*c > (int) nums[0].size() * nums.size() )
            return nums;
        else{
            vector<int> RawData;
            for(int i =0; i < nums.size(); i++){
                RawData.insert(RawData.end(), nums[i].begin(), nums[i].end());
            }
            vector<vector<int>> output(r, std::vector<int>(c, 0));
            int x = 0;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    output[i][j] = RawData[x];
                    x++;
                }
            }
            return output;
        }
    }
};

class Solution1 {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int m = nums.size(), n = nums[0].size(), o = r*c;
    if(m * n != o) return nums;
    vector<vector<int>> res(r, vector<int>(c,0));
    for(int i = 0; i < o; i++)
        res[i/c][i%c] = nums[i/n][i%n];
    return res;
    }
};
int main(int argc, char const *argv[]) {

    vector<vector<int>> output(3, std::vector<int>(3, 0));
    for (int i = 0; i < output.size(); i++) {
        for (int j = 0; j < output[i].size(); j++) {
            cout << output[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}