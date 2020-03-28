/* Binary Ssearch Tree */
#include <iostream>

using namespace std;


class BST{
	private:
	struct node
	{
		int data;
		struct node *left;
		struct node *right;
	};
	struct node *create_node(int data)
	{
		struct node *nn = (struct node*)malloc(sizeof(struct node));
		nn->data = data;
		nn->left = nullptr;
		nn->right = nullptr;
		return nn;
	}

	int ins(struct node *root)
	{
		// Case 1: If there is no left subtree.
		if(!root->left)
		{
			struct node *ptr = root->right;
			struct node *pptr = ptr;
			while(ptr != nullptr)
			{
				pptr = ptr;
				ptr = ptr->left;
			}
			return pptr->data;
		}
		// Case 2: If there is no right subtree
		else if(!root->right)
		{
			struct node *ptr = root->left;
			struct node *pptr = ptr;
			while(ptr != nullptr)
			{
				pptr = ptr;
				ptr = ptr->right;
			}
			return pptr->data;
		}
		// Case 3: If there are both subtrees present.
		else if(root->left && root->right)
		{
			struct node *ptr = root->right;
			struct node *pptr = ptr;
			while(ptr != nullptr)
			{
				pptr = ptr;
				ptr = ptr->left;
			}
			return pptr->data;
		}
		return root->data;
	}

	public:
	struct node *root;
	BST()
	{
		root = nullptr;
	}
	
	struct node *insert(int data)
	{
		// Create the node
		struct node *nn = create_node(data);
		// Check if its an empty tree
		if(!root)
		{
			root = nn;
		}
		// We now find the correct position for the node
		else
		{
			struct node *ptr = root;
			struct node *pptr =ptr;
			while(ptr != nullptr)
			{
				if(nn->data < ptr->data)
				{
					pptr = ptr;
					ptr = ptr->left;
				}
				else
				{
					pptr = ptr;
					ptr = ptr->right;
				}
			}
			if(nn->data < pptr->data)
			{
				pptr->left = nn;
			}
			else
			{
				pptr->right = nn;
			}
		}
		return root;
	}

	bool find(int data)
	{
		if(!root) return false;
		struct node *ptr = root;
		struct node *pptr = ptr;
		while(ptr != nullptr)
		{
			if(ptr->data == data) return true;
			else if(data < ptr->data)
			{
				pptr == ptr;
				ptr = ptr->left;
			}
			else
			{
				pptr = ptr;
				ptr = ptr->right;
			}
		}
		return false;
	}

	struct node *remove(int data)
	{
		// First we find the node that we want to delete
		bool isPresent = false;
		if(!root) return root;
		else
		{
			struct node *ptr = root;
			struct node *pptr = ptr;
			while(ptr != nullptr)
			{
				if(ptr->data == data)
				{
					isPresent = true;
					break;
				}
				else if(data < ptr->data)
				{
					pptr = ptr;
					ptr = ptr->left;
				}
				else
				{
					pptr = ptr;
					ptr = ptr->right;
				}
			}
			if(isPresent)
			{
				// Case 1: What if we are trying to remove the root node
				if(pptr == ptr)
				{
					int inos = ins(ptr);
					root = remove(inos);
					root->data = inos;
				}
				// Case 2: If the node to delete is a leaf node
				else if(!ptr->left && !ptr->right)
				{
					pptr->left == ptr ? pptr->left = nullptr : pptr->right = nullptr;
				}
				// Case 3a: If the node to delete has just one left child node.
				else if(ptr->left && !ptr->right)
				{
					pptr->left == ptr ? pptr->left = ptr->left : pptr->right = ptr->left;
				}
				// Case 3b: If the node to delete has just one right child node.
				else if(!ptr->left && ptr->right)
				{
					pptr->left == ptr ? pptr->left = ptr->right : pptr->right = ptr->right;
				}
				// Case 4: If the node to delete has 2 children.
				else if(ptr->left && ptr->right)
				{
					int inos = ins(ptr); // Find the inorder sucesssor.
					root = remove(inos);
					ptr->data = inos;
				}
				return root;
			}
			else return root;
		}
	}
	void inorder(struct node *root)
	{
		if(root)
		{
			inorder(root->left);
			cout<<root->data<<" ";
			inorder(root->right);
		}
	}
};


int main(int argc, char const *argv[])
{
	BST t;
	t.insert(10);
	t.insert(5);
	t.insert(15);
	t.insert(2);
	t.insert(14);
	t.insert(22);
	t.root = t.remove(10);
	t.inorder(t.root);
	return 0;
}
