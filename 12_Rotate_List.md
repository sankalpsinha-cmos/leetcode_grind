# Rotate List
Given a linked list, rotate the list to the right by __k__ places, where __k__ is non-negative.

### Example 1
```
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
```
### Example 2
```
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
```
### __Best Solution O(N) | O(1)__

Let __k__ be the no of places we want to right rotate the list. Let __n__ be the size of the list.

__The key idea here is if *__k__ = __n__* then the *__rotated list__ = __orginal list__*__

So when __k__ >= __n__ then we make __k__ = __k__%__n__. Then apply the rotate logic for (k < n).

__Rotate Logic__
* Find the length of the list by trversing to the end.
* Now make the list circular by making the tail point to the head.
* Now set __counter = n - k__
* Start traversing the list from the tail till the counter hits 0.
* Make the next node the head of the rotated list and the current node the tail.

```C++
ListNode* rotateRight(ListNode* head, int k) 
{
    // Simple base conditions
    if(!head || k == 0) return head;
    // Find the length of the list
    ListNode *tail = head;
    int size = 1;
    while(tail->next != nullptr)
    {
        size++;
        tail = tail->next;
    }
    // The Rotate Logic when k < n
    if(k < size)
    {
        // Make the list circular
        tail->next = head;
        // Now set counter = n-k and make a new ptr starting from the tail
        ListNode *ptr = tail;
        int counter = size-k;    
        while(counter)
        {
            ptr = ptr->next;
            counter--;
        }
        // Make the next node the head of new rotated list
        head = ptr->next;
        // Make the current node the tail
        ptr->next = nullptr;
        // return the new head
        return head;
    }
    // If k > n make k = k%n;
    else return rotateRight(head,k%size);
}
```
---
