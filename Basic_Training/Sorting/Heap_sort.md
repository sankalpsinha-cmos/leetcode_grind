# The heap sort.
```
Implement the heap sort.
```
### The Core Idea
1. Build a max-heap from the given array.
2. Remove the top element and replace it with the last element in the heap.
3. Rebalance the heap, using the siftUp method.
4. Keep doinf 3 till the heap size is 0.
5. Return the resulting array.
```
Time: O(NlogN)

First we build a min heap that takes O(N) time. Then we call the remove function N times. Each time it takes O(logN) time to run hence O(NlogN + N) total time. Which is O(NlogN).

Avg case = Best Case = Worst Case = O(NlongN) as in all cases we build a heap so the order of the original array has no effect on the algorithm.

Space: O(1)
As we pass the array as a reference we just use some local variables.
```
```C++
#include <vector>
using namespace std;
// Last 20-Nov-19 Time: 12:53 as of 12:00 Acc: Came up with best solution!!

// Used to build the heap and fix heap when deleting.
void siftDown(vector<int> *array, int index, int end)
{
	int left = 2*index + 1;
	int right = 2*index + 2;
	int largest = index;
	if(left <= end && array->at(left) > array->at(largest)) largest = left;
	if(right <= end && array->at(right) > array->at(largest)) largest = right;
	if(index != largest)
	{
		swap(array->at(largest),array->at(index));
		siftDown(array,largest,end);
	}
}

// We just swap the last element of the heap with the first and then call siftDown to fix the heap on the reduced size.

void remove(vector<int> *array, int size)
{
	swap(array->at(size),array->at(0));
	siftDown(array,0,size-1);
}


vector<int> heapSort(vector<int> array) {
// First build a heap.
	for(int i = array.size()/2 - 1; i >= 0; i--)
	{
		siftDown(&array,i,array.size()-1);
	}

// Now we remove each element from the heap to get the sorted array.
	int size = array.size()-1;
	while(size != -1)
	{
		remove(&array,size);
		size--;
	}
	return array;
}
```