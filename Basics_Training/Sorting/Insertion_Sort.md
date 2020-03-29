# Insertion Sort
```
Write a function that takes in an array of integers and returns a sorted version of that array. Use the Insertion Sort algorithm to sort the array.
```
```
Sample Input: [8,5,2,9,5,6,3]
Sample Output: [2,3,5,5,6,8,9]
```
* Time: O(N^2) | Θ(N^2) | Ω(N)
* Space: O(1)
```
Note: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.
```
```
What is Binary Insertion Sort?
We can use binary search to reduce the number of comparisons in normal insertion sort. Binary Insertion Sort uses binary search to find the proper location to insert the selected item at each iteration. In normal insertion, sorting takes O(i) (at ith iteration) in worst case. We can reduce it to O(logi) by using binary search. The algorithm, as a whole, still has a running worst case running time of O(n2) because of the series of swaps required for each insertion. Refer this for implementation.

Useful: When the array is small and partially sorted.

Try Implementing the Binary Insertion Sort
```


```C++
Code:

#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
  for(int i = 1; i < array.size(); i++)
	{
		int j = i - 1;
		int key = array[i];
		while(j>=0 && array[j] > key)
		{
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j+1] = key;
	}
	return array;
}
```