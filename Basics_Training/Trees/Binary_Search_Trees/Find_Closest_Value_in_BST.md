# Find the closest value in the BST

You are given a BST data structure consisting of BST nodes. Each BST node has an integer value stored in a property called "value" and two children nodes stored in properties called "left" and "right," respectively. A node is said to be a BST node if and only if it satisfies the BST property: its value is strictly greater than the values of every node to its left; its value is less than or equal to the values of every node to its right; and both of its children nodes are either BST nodes themselves or None (null) values. You are also given a target integer value; write a function that finds the closest value to that target value contained in the BST. Assume that there will only be one closest value.

```
Sample Input: target: 12
        10
       /   \
      5    15
    / \    / \
   2   5  13  22
  /     \
 1      14
Sample Output: 13
```
### Naive Solution
1. Put the inorder traversal of the BST into an array.
   say: 1,2,5,5,10,13,14,15,22.
2. Then find the number first number greater than the target in the array.
3. compute |target - first greater number| and |target - the number just before the first greater number|
   ie: |12 - 13| = 1 and |12 - 10| = 2
4. Then return the number with the lesser absolute difference. ie 13.

* Time: O(n) - As finding the inorder of a BST takes O(n) time.
* Space: O(n) - As we store the inorder in an array.

### Best Solution
1. Make a variable called 'closest' to keep track of the number that is currently the closest to the target number.
2. Initialise closest as a very large value. Starting at the root do 3,4 and 5 for each node till you reach a null node.
3. Compute |current node value - target| and |closest node value - target|
4. If |current node value - target| < |closest node value - target| then update closest = current node, else do not update closest node.
5. If target > current node go to the right subtree. Else go to the left subtree.
6. Return the value in the closest variable.

* Time: O(logn)
* Space: O(1)

```C++
int findClosestValueInBst(BST* tree, int target)
{
  static int closest = 99999; // Initialise the closest to a large value.
	if(!tree) return closest; // Handels null nodes and empty tree.
	abs(target - tree->value) < abs(target - closest) ? closest=tree->value:closest=closest;
	target > tree->value ? findClosestValueInBst(tree->right,target):findClosestValueInBst(tree->left,target);
}
```