# Invert a given Binary tree. Also called a mirror image of the Binary Tree.
Write a function that takes in a Binary Tree and inverts it. In other words, the function should swap every left node in the tree for its corresponding (mirrored) right node. Each Binary Tree node has a value stored in a property called "value" and two children nodes stored in properties called "left" and "right," respectively. Children nodes can either be Binary Tree nodes themselves or the None (null) value.
```
Input:    1
         /  \
        2    3
       / \   / \
      4   5 6   7
     / \
    8   9

          ||
          \/

Output:   1
        /   \
       3     2
      / \   / \
     7   6 5   4
              / \
             9   8
Note: The output is actually just the mirror image of the input.
```

### Best Method
1. For a node swap its left and right child.
2. Now recursively do the same for its left and right child.

* Time: O(N) - As we visit each node and do constant work for each node.
* Space: O(h) - We have to account for the stack height.
```C++
#include <vector>
using namespace std;

class BinaryTree {
  public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
    void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree* tree) {
  if((!tree) || (!tree->left && tree->right)) return;
	else
	{
		BinaryTree *ptr = tree->left;
		tree->left = tree->right;
		tree->right = ptr;
	}
	invertBinaryTree(tree->left);
	invertBinaryTree(tree->right);h
}
```