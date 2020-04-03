# Shifted Binary Search
```
Write a function that takes in a sorted array of integers as well as a target integer. The caveat is that the numbers in the array have been shifted by some amount; in other words, they have been moved to the left or the right by one or more positions. For example, [1, 2, 3, 4] might become [3, 4, 1, 2]. The function should use a variation of the Binary Search algorithm to find if the target number is contained in the array and should return its index if it is, otherwise -1.
```
```
Sample Input: [45,61,71,72,73,0,1,21,33,45],33
Sample Output: 8
```
### THE BEST APPROACH




* Time: O(logN) - Like normal binary search.
* Space: O(logN) if done recursively and O(1) if done iteratively.

```C++
// This is recursive code and takes O(logN) space. Try iterative for O(1).
#include <vector>
using namespace std;

int helper(vector<int> array, int low, int high, int target)
{
	if(low <= high)
	{
		int mid = (low + high)/2;

		if(array[mid] == target)return mid;

		else if(array[low] <= array[mid])
		{
			if(target >= array[low] && target < array[mid])
			{
				return helper(array,low,mid,target);
			}
			else return helper(array,mid+1,high,target);
		}
		else if(array[mid] <= array[high])
		{
			if(target > array[mid] && target <= array[high])
			{
				return helper(array,mid,high,target);
			}
			else return helper(array,low,mid-1,target);
		}
	}
	return -1;
}

int shiftedBinarySearch(vector<int> array, int target) {
  int index = helper(array,0,array.size()-1,target);
	return index;
}
```
