# Quicksort

```
BASIC BACKGROUND:

QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.
```
```
RECURSIVE ANALYSIS:

Rec Rel: T(N) = T(k) + T(N - 1 - k) + O(N)

The value of k defines where the array is split into two and depends on the nature of the piviot.
k can be anything between 'N/2' and 'N - 1'.

a: If k is N/2 the piviot is the median of the given numbers. This means that the array is split eaqually and the recurrence relation then becomes:
T(N) = 2T(N/2) + O(N) => O(NlogN)

b: If k is N-1 then the piviot is either the largest or the smallest number in the array and the recurrence relation then becomes:
T(N) = T(N-1) + T(0) + O(N).
T(N) = T(N-1) + 1 + O(N).
T(N) = T(N-1) + O(N) => O(N^2)

c: If k is N/4 then the recurence relation becomes:
T(N) = T(3N/4) + T(N/4) + O(N) => O(NlogN)
```
```
TIME ANALYSIS:

Best Case: As we can see the best case occurs when the piviot is always the median of the numbers.

Average Case: The Average case occurs when the piviot does not split the array into two parts such that part 1: N-1 and part 2: 0. Any other split like (N/4,3N/4), (N/8, 7N/8), (N/16, 15N/16) etc will result in the average case of O(NlogN).

Worst Case: Occurs when the piviot will split the array into part 1: N - 1 and part 2: 0 every time the partition function is called! The worst case is rare and occurs if the input array is sorted in asscending or descending order.
```
```
SPACE ANALYSIS:

Quick Sort uses only local variables in the partition function call but needs space for the function call stack. A simple implementation of Quick Sort will cause a space complexity of O(N) in the worst case when the array is divided into (N-1, 0) elements.

The good thing is that quick sort is a tail reccursive algorithm so tail call elimination leads to a space complexity of O(logN).

Read the code for the tail call eliminated version of Quick Sort.
```
```
REAL WORLD ADVANTAGE:

Although the worst case time complexity of QuickSort is O(n2) which is more than many other sorting algorithms like Merge Sort and Heap Sort, QuickSort is faster in practice, because its inner loop can be efficiently implemented on most architectures, and in most real-world data. QuickSort can be implemented in different ways by changing the choice of pivot, so that the worst case rarely occurs for a given type of data. However, merge sort is generally considered better when data is huge and stored in external storage.

Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any extra storage) whereas merge sort requires O(N) extra storage, N denoting the array size which may be quite expensive. Allocating and de-allocating the extra space used for merge sort increases the running time of the algorithm. Comparing average complexity we find that both type of sorts have O(NlogN) average complexity but the constants differ. For arrays, merge sort loses due to the use of extra O(N) storage space.
```

### Quick Sort using vector C++ STL (No Tail Call elimination)
```C++
#include <vector>
using namespace std;

int partition(vector<int> *array, int low, int high)
{
	int piviot = high;
	int i = low;
	int j = low - 1;
	for(; i < high; i++)
	{
		if(array->at(i) < array->at(piviot))
		{
			swap(array->at(++j),array->at(i));
		}
	}
	swap(array->at(++j),array->at(piviot));
	return j;
}

void qs(vector<int> *array, int low, int high)
{
	if(low < high)
	{
		int pi = partition(array,low,high);
		
		qs(array,low,pi - 1);
		qs(array,pi + 1, high);
	}
}

vector<int> quickSort(vector<int> array) {
  qs(&array,0,array.size()-1);
	return array;
}
```

### Quick Sort using vector C++ STL (Tail Call Elimination)
```
Ref to the Tail 'Recursion/tail_recursion_elimination.txt'
```