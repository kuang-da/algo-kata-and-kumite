#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*<-------------------------------------Key Point---------------------------------------->
A static variable inside a function keeps its value between invocations.
A static global variable or a function is "seen" only in the file it's declared in
  <-------------------------------------Key Point---------------------------------------->
n &= n - 1 ; [Get rid of one lowest bit of 1]
     <----- binary ---->
 n      n    n-1   n&(n-1)
--   ----   ----   -------
 0   0000   0111    0000 *
 1   0001   0000    0000 *
 2   0010   0001    0000 *
 3   0011   0010    0010
 4   0100   0011    0000 *
 5   0101   0100    0100
 6   0110   0101    0100
 7   0111   0110    0110
 8   1000   0111    0000 *
 9   1001   1000    1000
10   1010   1001    1000
11   1011   1010    1010
12   1100   1011    1000
13   1101   1100    1100
14   1110   1101    1100
15   1111   1110    1110
  <-------------------------------------------------------------------------------------->*/
class Solution {
  public:
	int hammingDistance(int x, int y) {
		// ^ XOR (bit operator)
		int dist = 0, n = x ^ y;
		// For while loop condition, any non-zero value means true
		while (n) {
			++dist;
			n &= n - 1;
		}
		return dist;
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;

	return 0;
}