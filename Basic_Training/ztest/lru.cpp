#include <iostream>
#include <unordered_map>

using namespace std;

// Custom node data type
struct node{
    string key;
    int value;
    struct node *next;
    struct node *prev;
};

// Double Linked List class
class DLL
{
    private:
    struct node *head;
    struct node *tail;
    public:
    // Constructor
    DLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Helper function to create a new node.
    struct node *createNode(string key, int value)
    {
        struct node *nn = new struct node();
        nn->key = key;
        nn->value = value;
        nn->next = nullptr;
        nn->prev = nullptr;
        return nn;
    }

    // Given a pointer to a node, make that node the head of the DLL
    void makeThisNodeHead(struct node *ptr)
    {
        if(head == ptr) return;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        ptr->prev = nullptr;
        ptr->next = head;
        head = ptr;
    }

    // Insert a new node at the head of the DLL.
    struct node *insertNodeAtHead(string key, int value)
    {
        struct node *nn = createNode(key,value);
        
        if(!head || !tail)
        {
            head = nn;
            tail = nn;
        }
        else
        {
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
        return nn;
    }

    // Delete the tail node of the DLL
    void delTail()
    {
        if(tail != head)
        {
            tail = tail->prev;
            delete(tail->next);
            tail->next = nullptr;
        }
        else
        {
            delete(tail);
            head = nullptr;
            tail = nullptr;
        }
        
    }

    // Return if the DLL is empty or not
    bool isEmpty()
    {
        if(head && tail) return false;
        return true;
    }

    // Get the Key attribute of the head of the DLL
    string getHeadKey()
    {
        if(head) return head->key;
        else return "";
    }

    // Get the key attribute of the tail of the DLL 
     string getTailKey()
    {
        if(tail) return tail->key;
        return "";
    }

    // Helper function to display the DLL (used in displayCacheDLL)
    void disp()
    {
        struct node *ptr = head;
        while(ptr != nullptr)
        {
            cout<<"Key: "<<ptr->key<<" Value: "<<ptr->value<<endl;
            ptr = ptr->next;
        }
    }

};

// Least Recently Used cache
class LRU{
    private:
        int maxSize;
        int cur_size;
        DLL l;
    unordered_map<string,struct node *> m;
    public:
    // Constructor
    LRU(int maxSize)
    {
        this->maxSize = maxSize;
        cur_size = 0;
    }
    // Insert a new key-value pair into the cache
    void insert(string key, int value)
    {
        // Check if the key is already present in cache
        if(m.find(key) != m.end())
        {
            // If already present then just update its value and make it the head of the DLL.
            auto itr = m.find(key);
            itr->second->value = value;
            l.makeThisNodeHead(itr->second);
        }
        // If the key is new to the cache
        else
        {
            //Check if there is enough space in the cache
            if(cur_size < maxSize)
            {
                // Create a new node at the head of the DLL. Also add the address of this new node to the unordered map.
                cur_size++;
                struct node *new_node_address = l.insertNodeAtHead(key,value);
                m.insert({key,new_node_address});
            }
            // If the cache is full
            else
            {
                // Make space by removing the Least Recently used element.
                // First delete it from the unordered map.
                m.erase(l.getTailKey());
                // Second delete it from the DLL.
                l.delTail();
                // Now we have size to decrease current size of the cache.
                cur_size--;
                // Now insert the new key-value pair into the cache.
                insert(key,value);
            }
        }
    }

    // Get the value given the key from the cache
    int getValueFromKey(string key)
    {
        // Check if the key is in the cache
        auto itr = m.find(key);
        if(itr != m.end())
        {
            // As now this node becomes the most recently accessed node make sure its at the head of the DLL.
            l.makeThisNodeHead(itr->second);
            return itr->second->value;
        }
        else return -1;
    }

    // Get the most recently accessed key from the cache
    string getMostRecentKey()
    {
        if(!l.isEmpty())
        {
            return l.getHeadKey();
        }
        else return "";
    }
    
    // To display the entire DLL (sanity check)
    void displayCacheDLL()
    {
        cout<<"\nThe DLL looks like this: "<<endl;
        l.disp();
    }

    // To display the entire Unordered_Map (sanity check)
    void displayCacheMap()
    {
        cout<<"\nThe hash map looks like this: "<<endl;
        auto itr = m.begin();
        for(;itr != m.end(); itr++)
        {
            cout<<"Key: "<<itr->first<<" Value: "<<itr->second<<endl;
        }
    }
};

// Main
int main(int argc, char const *argv[])
{
    //int maxSize;
    //cout<<"Enter the maxSize of the cache: ";cin>>maxSize;
    LRU lru(1);
    cout<<lru.getValueFromKey("a")<<endl;
    lru.insert("a",99);
    cout<<lru.getMostRecentKey()<<endl;
    cout<<lru.getValueFromKey("a")<<endl;
    lru.insert("a",0);
    cout<<lru.getMostRecentKey()<<endl;
    cout<<lru.getValueFromKey("a")<<endl;
    return 0;
}
