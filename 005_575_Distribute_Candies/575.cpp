#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
// Time complexity
// std::sort
//      average case linearithmic (nlogn) time complexity.
// std:: stable_sort
//      quasilinear worst case time complexity (n log^2 n)
// STL: unordered_set
// Unordered sets are containers that store unique elements 
// in no particular order, and which allow for fast retrieval 
// of individual elements based on their value.
class Solution {
public:
  int distributeCandies(vector<int>& candies) {
    unordered_set<int> sis;
    for(int k:candies){
      sis.insert(k);
    }
    return min(sis.size(), candies.size()/2);
  }
};

class Solution1 {
public:
  int distributeCandies(vector<int>& candies) {
    return min( (unordered_set<int>(candies.begin(), candies.end())).size(), candies.size() / 2);
  }
};
/*
  class Solution2 {
  public:
  int distributeCandies(vector<int>& candies) {
  size_t kind = 0;
  sort(candies.begin(), candies.end());
  for(int i = 0; i < candies.size(); i++){
  kind += i==0 || candies[i] != candies[i-1];
  }
        
  return min(kind, candies.size()/2);
  }
  }; 

  class Solution3 {
  public:
  int distributeCandies(vector<int>& candies) {
  int kind = 0;
  sort(candies.begin(), candies.end());
  for(int i = 0; i < candies.size(); i++){
  kind += i==0 || candies[i] != candies[i-1];
  }
        
  return min(kind, (int)candies.size()/2);
  }
  };
*/
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
  vector<int> Vtest = {1,4,2,3,9,13};
  return 0;
}
