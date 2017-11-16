#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
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
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), (nums.begin() + nums.size()));
        int sum = 0;
        for(int i = 0; i < nums.size(); i+=2){
            sum += nums[i];
        }
        return sum;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    // Good way to initilize vector
    // int myints[] = {4, 3, 2, 1};
    // std::vector<int> v ( myints, myints + (sizeof(myints) / sizeof(int)) );
    // for (int i = 0; i < v.size(); ++i) {
    //     cout << v[i] << endl;
    // }
    // // Sort vector
    // sort(v.begin(), v.begin() + v.size());
    // for (int i : v)
    //     cout << "i = " << i << endl;
    std::vector<int> Vtest = {1,4,2,3,9,13};
    cout << solution.arrayPairSum(Vtest)<<endl;
    return 0;
}