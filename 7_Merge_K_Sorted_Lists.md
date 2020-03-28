# Merge K Sorted Lists

Merge __k__ sorted linked lists each of size __N__ and return it as one sorted list. Analyze and describe its complexity.

### Example 1
```
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
```
### __Naive Solution O(N^2) | O(N^2)__

Use the merge sort merging method to merge two sorted lists. Do this for all the lists one by one.

```C++
class Solution {
public:
    
    ListNode *merge(ListNode *p1, ListNode *p2)
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        
        while(p1 && p2)
        {
            if(p1->val <= p2->val)
            {
                if(!head)
                {
                    ListNode *nn = new ListNode(p1->val);
                    head = nn;
                    tail = nn;
                    p1 = p1->next;
                }
                else
                {
                    ListNode *nn = new ListNode(p1->val);
                    tail->next = nn;
                    tail = nn;
                    p1 = p1->next;
                }
            }
            else
            {
                if(!head)
                {
                    ListNode *nn = new ListNode(p2->val);
                    head = nn;
                    tail = nn;
                    p2 = p2->next;
                }
                else
                {
                    ListNode *nn = new ListNode(p2->val);
                    tail->next = nn;
                    tail = nn;
                    p2 = p2->next;
                }
            }
        }
        while(p1)
        {
            if(!head)
                {
                    ListNode *nn = new ListNode(p1->val);
                    head = nn;
                    tail = nn;
                    p1 = p1->next;
                }
                else
                {
                    ListNode *nn = new ListNode(p1->val);
                    tail->next = nn;
                    tail = nn;
                    p1 = p1->next;
                }
        }
        while(p2)
        {
            if(!head)
                {
                    ListNode *nn = new ListNode(p2->val);
                    head = nn;
                    tail = nn;
                    p2 = p2->next;
                }
                else
                {
                    ListNode *nn = new ListNode(p2->val);
                    tail->next = nn;
                    tail = nn;
                    p2 = p2->next;
                }
        }
        return head;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *fl;
        if(lists.size() == 0) return nullptr;
        else if(lists.size() == 1)
        {
            fl = lists[0];
            return fl;
        }
        else if(lists.size() == 2)
        {
            fl = merge(lists[0],lists[1]);
            return fl;
        }
        else
        {
            fl = merge(lists[0],lists[1]);
            for(int i = 2; i < lists.size(); i++)
            {
                fl = merge(fl, lists[i]);
            }
            return fl;
        }
        
    }
};
```
---

### __Better Solution O(NK log ) | O(NK)__

We can use a __Min Heap__ AKA __Priority Queue__. First add each element of the given lists into the __Priority Queue__ . Now pop till its empty and construct an new __List__ using the poped elements. Return the new __List__.

```C++
 ListNode* mergeKLists(vector<ListNode*>& lists) {
       // Define a min heap using STL.
       priority_queue <int, vector<int>, greater<int>> q;

       // Add all the elements in each list to this min heap.
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode *ptr = lists[i];
            while(ptr)
            {
                q.push(ptr->val);
                ptr = ptr->next;
            }
        }

        // Define the head and tail for the new list
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        // Pop till the min heap is empty and also build the final list
        while(q.empty() == false)
        {
            if(!head)
            {
                ListNode *nn = new ListNode(q.top());
                q.pop();
                head = nn;
                tail = nn;
            }
            else
            {
                ListNode *nn = new ListNode(q.top());
                q.pop();
                tail->next = nn;
                tail = nn;
            }
        }
        return head;
    }
```