# Validate that a given Binary Tree is a BST.

### NAIVE LOGIC
1. Store the inorder traversal of the BST.
2. Check if the inorder traversal is sorted. If yes the BT is a BST, else not.


* Time: O(N) - As we visit each node at least once when we find the inorder.
* Space: O(h) - Due to recursion the call stack will have a max height as that of the depth of the tree.

### BEST SOLUTION

Idea: Each node in a BST is bounded by a min and a max value.
1. The root node is bounded as: -inf < root > infy.
2. For any other node c:
```
   5
  /
3
 \
  c
Here c must be smaller than 5 and greater than 3. hence 3 < c > 5.
```
* Time: O(N)
* Space: O(h)

```C++
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool helper(BST *root, int low, int high)
{
	if(!root) return true;
	if(low <= root->value && root->value < high) return(helper(root->left,low,root->value) && helper(root->right,root->value,high));
	return false;
}

bool validateBst(BST *tree) {
  return helper(tree,INT_MIN,INT_MAX);
}
```