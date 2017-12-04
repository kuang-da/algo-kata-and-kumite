#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/
class Solution{
  /*
    Very simple C++ solution
    Firstly, we put each element x in nums[x - 1]. Since x ranges from 1 to N, then x - 1 ranges from 0 to N - 1, it won't exceed the bound of the array.
    Secondly, we check through the array. If a number x doesn't present in nums[x - 1], then x is absent.

    Since the elements range from 1 to N, then each element is corresponding to a index. Maybe you can be inspired by counting sort.
  */
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
	size_t i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        for (i = 0; i < nums.size(); i++) {
	  if ((size_t)nums[i] != i + 1) res.push_back(nums[i]);
        }
        return res;
    }

  vector<int> findDuplicates2(vector<int>& nums) {
        vector<int> res;
        for(size_t i = 0; i < nums.size(); i ++){
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1] > 0) res.push_back(abs(nums [i]));
        }
        return res;
    }
};


int main(int argc, char const *argv[]) {

	return 0;
}
