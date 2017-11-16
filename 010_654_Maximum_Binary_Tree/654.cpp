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
/*
  Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

  The root is the maximum number in the array.
  The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
  The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
  Construct the maximum tree by the given array and output the root node of this tree.

  Example 1:
  Input: [3,2,1,6,0,5]
  Output: return the tree root node representing the following tree:

  6
  /   \
  3     5
  \    / 
  2  0   
  \
  1
  Note:
  The size of the given array will be in the range [1,1000].
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void printInorder(struct TreeNode* TreeNode){
    if( TreeNode == NULL)
	return;
    // First print left side
    printInorder(TreeNode->left);
    // Then print the center node
    printf("%d", TreeNode->val);
    // Finally, print the right side
    printInorder(TreeNode->right);
}

TreeNode* constructMaximumBinaryTree(vector<int> nums) {
    auto iter = std::max_element(nums.begin(), nums.end());
    int idx = std::distance(nums.begin(), iter);

    for(auto elem: nums){
	std::cout << elem << " ";
    }
    std::cout << "\n";

    TreeNode* root = new TreeNode(nums[idx]);

    if(idx == nums.size() - 1 ){

    }
    else{
	std::vector<int> rightSubtree(nums.begin() + idx + 1, nums.end());
	auto rightNode = constructMaximumBinaryTree(rightSubtree);
	root-> right = rightNode;
    }

    if(idx == 0){
    }
    else{
	std::vector<int> leftSubtree(nums.begin(), nums.begin()+idx);
	auto leftNode = constructMaximumBinaryTree(leftSubtree);
	root -> left = leftNode;
    }

    return root;
}

int main(int argc, char const *argv[]) {
    std::vector<int> elem = {3,2,1,6,0,5} ;
    auto root = constructMaximumBinaryTree(elem);
    printInorder(root);
    return 0;
}
