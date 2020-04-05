// BST Contruction
#include <iostream>

using namespace std;

class BST{
    private:
    struct node{
        int data;
        struct node *left;
        struct node *right;
    };

    // Create a new node
    struct node *create_node(int data)
    {
        struct node *nn = (struct node *)malloc(sizeof(struct node));
        nn->data = data;
        nn->left = nullptr;
        nn->right = nullptr;
        return nn;
    }

    public:
    struct node *root;

    BST()
    {
        root = nullptr;
    }

    // Insert
    void add(int data)
    {
        struct node *nn = create_node(data);
        if(!root) root = nn;
        else
        {    
            struct node *ptr = root;
            struct node *pptr = ptr;
            while(ptr != nullptr)
            {
                if()
            }
        }
    }
};



int main(int argc, char const *argv[])
{
    
    return 0;
}
