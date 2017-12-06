/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

Idea:
Pick out tallest group of people and sort them in a subarray (S). Since there's no other groups of people taller than them, therefore each guy's index will be just as same as his k value.

For 2nd tallest group (and the rest), insert each one of them into (S) by k value. So on and so forth.

E.g.
input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
subarray after step 1: [[7,0], [7,1]]
subarray after step 2: [[7,0], [6,1], [7,1]]

https://leetcode.com/problems/queue-reconstruction-by-height/discuss/
*/
#include <vector>
using namespace std;
class Solution {
public:

  vector<pair<int, int>> reconstructQueue0(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(),[](pair<int,int> p1, pair<int,int> p2){
	return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
      });
    vector<pair<int,int>> sol;
    for (auto person : people){
      sol.insert(sol.begin() + person.second, person);
    }
    return sol;
  }
  
  vector<pair<int, int>> reconstructQueue1(vector<pair<int, int>>& people) {
    auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
      { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
    sort(people.begin(), people.end(), comp);
    vector<pair<int, int>> res;
    for (auto& p : people) 
      res.insert(res.begin() + p.second, p);
    return res;
  }
};
