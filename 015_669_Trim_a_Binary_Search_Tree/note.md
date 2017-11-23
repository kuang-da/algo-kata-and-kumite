# Binary Search Tree

Binary search trees (BST) are a particular type of container: data structures that store "items" in memory. 

They allow fast lookup, addition and removal of items, and can be used to implement either dynamic sets of items, or lookup tables that allow finding an item by its key (e.g., finding the phone number of a person by name).

When looking for a key in a tree (or a place to insert a new key), they traverse the tree from root to leaf, making comparisons to keys stored in the nodes of the tree and deciding, on the basis of the comparison, to continue searching in the left or right subtrees.
```
    8
   / \
  3   10
 / \    \
1   6    14
   / \   /
  4   7 13
```

# Solution

If the root value in the range [L, R]
      we need return the root, but trim its left and right subtree;

else if the root value < L
      because of binary search tree property, the root and the left subtree are not in range;
      we need return trimmed right subtree.

else
      similarly we need return trimmed left subtree.
	  
	  
