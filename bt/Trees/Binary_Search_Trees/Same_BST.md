# Same BST

An array of integers is said to represent the Binary Search Tree (BST) obtained by inserting each integer in the array (from left to right) into the BST. Write a function that takes in two arrays of integers and returns a boolean representing whether or not these arrays represent the same BST. Note that you are not allowed to construct any BSTs in your code. A BST is a Binary Tree that consists only of BST nodes. A node is said to be a BST node if and only if it satisfies the BST property: its value is strictly greater than the values of every node to its left; its value is less than or equal to the values of every node to its right; and both of its children nodes are either BST nodes themselves or None (null) values.

### Example 1
```
(You are actually given the insertion sequence of the two BSTs)
Sample input: [10, 15, 8, 12, 94, 81, 5, 2, 11], [10, 8, 5, 15, 2, 12, 11, 94, 81]
Sample Output: True
```

### Best Solution O(N^2) | O(N^2)
The main idea comes from the following fact:
1. Two BSTs are said to be the same if the have the exact same structure.
2. This means they must have the same no of nodes, the same left and right sub-trees for each node.

To check if two BSTs are the same, we first compare their root nodes.
```
If root(BST_1) != root(BST_2) then then the two BSTs are not the same.

Else recursively compare the root nodes of the left and right sub-trees of the two BSTs with each other.
```

```C++
#include <vector>

using namespace std;

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
	if(arrayOne.empty() && arrayTwo.empty()) return true;
	if(arrayOne[0] != arrayTwo[0]) return false;
	if(arrayOne.size() != arrayTwo.size()) return false;
	vector<int> LST_One, LST_Two, RST_One, RST_Two;
	for(int i = 1; i < arrayOne.size(); i++)
	{
		if(arrayOne[i] < arrayOne[0]) LST_One.push_back(arrayOne[i]);
		else RST_One.push_back(arrayOne[i]);
	}
	for(int i = 1; i < arrayTwo.size(); i++)
	{
		if(arrayTwo[i] < arrayTwo[0]) LST_Two.push_back(arrayTwo[i]);
		else RST_Two.push_back(arrayTwo[i]);
	}
	return (sameBsts(LST_One,LST_Two) && sameBsts(RST_One,RST_Two)); 
}
```
---