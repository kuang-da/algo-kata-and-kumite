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
class Solution {
  public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        int y = board.size();
        cout << "y:" << y << endl;
        int x = board[0].size();
        cout << "x:" << x << endl;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if ( (board[i][j] == 'X') ) {
                    cout << "find x[" << i << "][" << j << "]" << endl;
                    if ( ( i == 0 ) || ( j == 0) ) {
                        if ( ( i == 0 ) && ( j == 0) )
                            count++;
                        else if (( i == 0 ) && (board[i][j - 1] != 'X'))
                            count++;
                        else if (( j == 0 ) && (board[i - 1][j] != 'X'))
                            count++;
                    } else if ( (board[i - 1][j] != 'X') && (board[i][j - 1] != 'X') )
                        count++;
                }
            }
        }
        return count;
    }
};

class Solution01 {
  public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if(( board[i][j] == 'X') && ( (i == 0) || (board[i-1][j] != 'X') ) && ( (j == 0)||(board[i][j-1] != 'X') ))
                    count++;
            }
        }
        return count;
    }
};
// Could also think about XOR method
int main(int argc, char const *argv[]) {
    std::vector<char> v0 = {'X', '.', '.', 'X'};
    std::vector<char> v1 = {'.', '.', '.', 'X'};
    std::vector<char> v2 = {'.', '.', '.', 'X'};
    std::vector< std::vector<char>> v;
    v.push_back(v0);
    v.push_back(v1);
    v.push_back(v2);
    Solution01 solution;

    int result = solution.countBattleships(v);
    cout << "Return :" << result << endl;

    return 0;
}