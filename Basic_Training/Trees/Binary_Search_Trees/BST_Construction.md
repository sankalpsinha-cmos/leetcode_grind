# Binary Search Tree Implementation

Write a BST class that implements Insert, Search and Remove on a BST.

### Remove Logic
1. If the 'node to delete' is a leaf just assign the parent of the 'node to delete' as nullptr;
2. If the 'node to delete' has exactly one child. Make the parent of the 'node to delete' point to the child of 'node to delete'. Then free 'node to delete'.
3. If the 'node to delete' has two children. Then first find the inorder successor of 'node to delete'. Then delete the inorder successor from the tree. Finally replace the value of 'node to delete' with the value of the inorder successor.

### Inorder Successor Logic: (Be careful during implementation, this has high chance of mistakes)
1. Do not Assume that if root->left != nullptr and root->right != nullptr then everything is fine.
2. We must take 3 cases into account namely:

	1. If root->left == nullptr. Then get the leftmost value in the right subtree of root.
	2. If root->right == nullptr. Then get the rightmost value in the left subtree of root.
	3. If root->right != nullptr and root->left != nullptr then use point 1.

3. Revise the way to find the inorder successor, this is the crux of BST operations.

### Time Complexity:
Note that it is not neccessary that the height of the BST will be O(logN).
In general it will be O(h) or in worst case O(N).
1. Search: O(N) | &theta;(logh) | &Omega;(logN)
2. Insertion: O(N) | &theta;(logh) | &Omega;(logN)
3. Deletion: O(N) | &theta;(logh) | &Omega;(logN)

### Space Complexity:
All operations take O(1) Space Complexity.



```C++
Note: Read this code carefully. Especially how to find the inorder successor.

#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
  public:
    int value;
    BST* left;
    BST* right;

    BST(int val) {
      value = val;
      left = NULL;
      right = NULL;
    }

	int ins(BST *root)
	{
		BST *ptr;
		BST *pptr;
		if(root->right && !root->left)
		{
			ptr = root->right;
			pptr = ptr;
			while(ptr != nullptr)
			{
				pptr = ptr;
				ptr = ptr->left;
			}
			return pptr->value;
		}
		else if(root->left && !root->right)
		{
			ptr = root->left;
			pptr = ptr;
			while(ptr != nullptr)
			{
				pptr = ptr;
				ptr = ptr->right;
			}
			return pptr->value;
		}
		else if(root->left && root->right)
		{
				ptr = root->right;
				pptr = ptr;
			while(ptr != nullptr)
			{
				pptr = ptr;
				ptr = ptr->left;
			}
			return pptr->value;
		}
		return root->value;
	}

    BST& insert(int val) {
			BST *new_node = new BST(val); // Create a new node.
			BST *ptr = this; // as this fucntion will be called by the root node, and this keyword returns the address of the the calling node, ie the root node.
			BST *pptr = ptr; // Pointer to keep track of the parent node.
			while(ptr != nullptr)
			{
				pptr = ptr;
				val >= ptr->value?ptr = ptr->right:ptr = ptr->left;
			}
			val >= pptr->value?pptr->right = new_node:pptr->left = new_node;
      return *this;
    }

    bool contains(int val) {
      BST *ptr = this;
			while(ptr != nullptr)
			{
				if(ptr->value == val)return true;
				val >= ptr->value?ptr = ptr->right:ptr = ptr->left;
			}
			return false;
    }

    BST& remove(int val) {
			while(this->contains(val) == true)
			{
				// Lets find the value in the BST.
				BST *ptr = this;
				BST *pptr = ptr;
				bool found = false;
				while(ptr != nullptr)
				{
					if(ptr->value == val)
					{
						found = true;
						break;
					}
					pptr = ptr;
					val >= ptr->value?ptr = ptr->right:ptr = ptr->left;
				}
				if(found)
				{
					//Case 0: The node to delete is the root node
					if(ptr == pptr)
					{
						int inorder_successor = ins(ptr); // Get the inorder successor of the node to be deleted.
						this->remove(inorder_successor);
						ptr->value = inorder_successor;
					}
					// Case 1: The node to be removed is a leaf node.
					else if(!ptr->left && !ptr->right)
					{
						pptr->left == ptr?pptr->left = nullptr:pptr->right = nullptr;
					}
					// Case 2a: The node to be removed has exactly one child.
					else if(ptr->left && !ptr->right) // Has a left child
					{
						pptr->left == ptr?pptr->left = ptr->left:pptr->right = ptr->left;
					}
					// Case 2b: The node to be removed has exactly one child.
					else if(ptr->right && !ptr->left) // Has a right child
					{
						pptr->left == ptr?pptr->left = ptr->right:pptr->right = ptr->right;
					}
					// Case 3: The node to be removed has two children.
					else if(ptr->left && ptr->right)
					{
						int inorder_successor = ins(ptr); // Get the inorder successor of the node to be deleted.
						this->remove(inorder_successor);
						ptr->value = inorder_successor;
					}
			}
		}
  	return *this;
    }
};
```
