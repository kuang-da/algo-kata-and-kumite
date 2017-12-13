/*
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.
*/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
  // O(n), solution
    int singleNonDuplicate(vector<int>& nums) {
        int previouseInt = nums[0];// Maybe set it as min?
        bool isTheSecondNum = true;
        for(size_t i = 1; i < nums.size(); i++){
            if(i == nums.size()-1){
                // This is the last elements of the list. Must be the target
                cout<< "Case0, current num: "<<nums[i];
                return nums[i];
            }else if(!isTheSecondNum){
                // This a new element. So just update previousInt and check next
                previouseInt = nums[i];
                isTheSecondNum = true;
                cout<< "Case1, current num: "<<nums[i];
            }else if(previouseInt == nums[i] && isTheSecondNum){
                //Find a pair of element, update parameters and keep parsing
                previouseInt = nums[i];
                isTheSecondNum = false;
                cout<< "Case2, current num: "<<nums[i];
                
            }else if(previouseInt != nums[i] && isTheSecondNum){
                // The second num is different with the previous one. So that is the target
                cout<< "Case3, current num: "<<nums[i];
                return nums[i-1];
            }
                
        }
        
    }

  // O(log n) solution, binary search tree

      int singleNonDuplicate2(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid-1]) right = mid - 2;
                else if (nums[mid] == nums[mid+1]) left = mid + 2;
                else return nums[mid];
            }
            else {
                if (nums[mid] == nums[mid-1]) left = mid + 1;
                else if (nums[mid] == nums[mid+1]) right = mid - 1;
            }
        }
        return nums[left];
    }
};
