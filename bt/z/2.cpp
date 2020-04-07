// BST Construction: Insertion, Search, Deletion
#include <iostream>

using namespace std;

class BST{
    private:
    struct node{
        int data;
        struct node *left;
        struct node *right;
    };
    struct node *create_node(int data)
    {
        struct node *nn = (struct node *)malloc(sizeof(struct node));
        nn->data = data;
        nn->left = nullptr;
        nn->right = nullptr;
        return nn;
    }
      void inorder(struct node *root)
    {
        if(root)
        {
            inorder(root->left);
            std::cout<<root->data<<" ";
            inorder(root->right);
        }
    }
// Inorder Successor or Predecessor
    int inorder_successor(struct node *root)
    {
        struct node *ptr = root;
        // There is no left or right sub-trees
        if(!ptr->left && !ptr->right) return ptr->data;
        // There is just a left sub-tree
        else if(ptr->left && !ptr->right)
        {
            struct node *p = ptr->left;
            struct node *pp = p;
            while(p != nullptr)
            {
                pp = p;
                p = p->right;
            }
            return pp->data;
        }
        // There is just a right sub-tree
        else if(!ptr->left && ptr->right)
        {
            struct node *p = ptr->right;
            struct node *pp = p;
            while(p != nullptr)
            {
                pp = p;
                p = p->left;
            }
            return pp->data;
        }
        // There are both a left and right sub-tree
        else if(ptr->left && ptr->right)
        {
            struct node *p = ptr->left;
            struct node *pp = p;
            while(p != nullptr)
            {
                pp = p;
                p = p->right;
            }
            return pp->data;
        }
        return ptr->data;
    }
// Height 
    int height(struct node *root)
    {
        if(root) return 1 + max(height(root->left),height(root->right));
        return 0;
    }
// No of Leaf Nodes
    int noln(struct node *root)
    {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        else
        {
            return (noln(root->left) + noln(root->right));
        }
    }
// PUBLIC --- PUBLIC
    public:
    struct node *root;
// Constructor
    BST()
    {
        root = nullptr;
    }
// Inorder Traversal
  
    void inorder_caller()
    {
        struct node *ptr = root;
        inorder(ptr);
    }
// Tree Properties:

// Height
int find_height()
{
    struct node *ptr = root;
    return height(ptr); 
}
// No of LEaf Nodes
int find_noln()
{
    struct node *ptr = root;
    return noln(ptr); 
}

// Insert
    void add(int data){
        struct node *nn = create_node(data);
        if(!root) root = nn;
        else
        {
            struct node *ptr = root;
            struct node *pptr = ptr;
            while(ptr != nullptr)
            {
                if(nn->data >= ptr->data)
                {
                    pptr = ptr;
                    ptr = ptr->right;
                }
                else
                {
                    pptr = ptr;
                    ptr = ptr->left;
                }
            }
            if(nn->data >= pptr->data) pptr->right = nn;
            else pptr->left = nn;
        }
    }
// Search
    bool search(int data)
    {
        if(!root) return false;
        struct node *ptr = root;
        while(ptr != nullptr)
        {
            if(ptr->data == data) return true;
            else if(data >= ptr->data) ptr = ptr->right;
            else ptr = ptr->left;
        }
        return false;   
    }
// Delete
    void remove(int data)
    {
        if(!root) return;
        // Search for the data
        bool found = false;
        struct node *ptr = root;
        struct node *pptr = ptr;
        while(ptr != nullptr)
        {
            if(ptr->data == data)
            {
                found = true;
                break;
            }
            else if(data >= ptr->data)
            {
                pptr = ptr;
                ptr = ptr->right;
            }
            else
            {
                pptr = ptr;
                ptr = ptr->left;
            }
        }
        if(found)
        {
            //Case 0 - The node to delete is the root node
            if(ptr == pptr)
            {
                int ins = inorder_successor(ptr);
                if(ins == ptr->data)
                {
                    root = nullptr;
                    return;
                }
                remove(ins);
                ptr->data = ins;
            }
            //Case 1 - The node to delete is a leaf node
            else if(!ptr->left && !ptr->right)
            {
                pptr->left == ptr?pptr->left = nullptr : pptr->right = nullptr;
                delete(ptr);
            }
            // Case 2a - The node to delete has a left child
            else if(ptr->left && !ptr->right)
            {
                pptr->left == ptr?pptr->left = ptr->left : pptr->right = ptr->left;
                delete(ptr);
            }
            // Case 2b - The node to delete has a right child
            else if(!ptr->left && ptr->right)
            {
                pptr->left == ptr?pptr->left = ptr->right : pptr->right = ptr->right;
                delete(ptr); 
            }
            // Case 3 - The node to delete has both a left and right child
            else if(ptr->left && ptr->right)
            {
                int ins = inorder_successor(ptr);
                remove(ins);
                ptr->data = ins;
            }
        }
    }
};



int main(int argc, char const *argv[])
{
    BST *t = new BST();
    int a[] = {8,3,10,1,6,14,4,7,13};
    for(int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        t->add(a[i]);
    }
    t->inorder_caller();
    cout<<endl;
    cout<<"The Height of the BST: "<<t->find_height()<<endl;
    cout<<"The No of Leaf nodes in the BST: "<<t->find_noln()<<endl;
    delete(t);
    return 0;
}
