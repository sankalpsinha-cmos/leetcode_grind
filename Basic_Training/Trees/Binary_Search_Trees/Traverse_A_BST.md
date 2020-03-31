# Traverse a BST

You are given a BST data structure consisting of BST nodes. Each BST node has an integer value stored in a property called "value" and two children nodes stored in properties called "left" and "right," respectively. A node is said to be a BST node if and only if it satisfies the BST property: its value is strictly greater than the values of every node to its left; its value is less than or equal to the values of every node to its right; and both of its children nodes are either BST nodes themselves or None (null) values. Write three functions that take in an empty array, traverse the BST, add its nodes' values to the input array, and return that array. The three functions should traverse the BST using the in-order traversal, pre-order traversal, and post-order traversal techniques, respectively.

```
Sample Input: target:
        10
       /   \
      5    15
    / \    / \
   2   5  13  22
  /     \
 1      14
Sample Output:
Inorder: [1,2,5,5,10,15,22]
Preorder: [10,5,2,1,5,15,22]
Postorder: [1,2,5,5,22,15,10]
```

### Time Complexity: O(N) | &theta;(logh) | &Omega;(logN) 
### Space Complexity: O(h) generally but in this case as we return an array so O(N).

```C++
#include <vector>
using namespace std;

class BST {
  public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};

vector<int> inOrderTraverse(BST* tree, vector<int> array) {
	if(tree)
	{
		array = inOrderTraverse(tree->left,array);
		array.push_back(tree->value);
		array = inOrderTraverse(tree->right,array);
	}
	return array;
}

vector<int> preOrderTraverse(BST* tree, vector<int> array) {
	if(tree)
	{
		array.push_back(tree->value);
		array = preOrderTraverse(tree->left,array);
		array = preOrderTraverse(tree->right,array);
	}
	return array;
}

vector<int> postOrderTraverse(BST* tree, vector<int> array) {
	if(tree)
	{
		array = postOrderTraverse(tree->left,array);
		array = postOrderTraverse(tree->right,array);
		array.push_back(tree->value);
	}
	return array;
}
```