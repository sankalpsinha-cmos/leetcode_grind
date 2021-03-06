# Search for a range
```
Write a function that takes in a sorted array of integers as well as a target integer. The function should use a variation of the Binary Search algorithm to find a range of indices in between which the target number is contained in the array and should return this range in the form of an array. The first number in the output array should represent the first index at which the target number is located while the second number should represent the last index at which the target number is located. The function should return [-1, -1] if the number is not contained in the array.
```
```
Basically we are given a sorted array of integers, there is a number in the array that is repeated a bunch of times. We need to find the first and last index in the array at which it can be found i.e: its range. We should use some modified version of Binary Search.
```
Example 1
```
Sample Input: [0,1,21,33,45,45,45,45,45,45,61,71,73],45
Sample Output: [4,9];
```
### THE BEST IDEA



* Time: O(2logN) = O(logN)
* Space: O(logN) if implemented recursively and O(1) is implemented iteratively.

```C++
#include <vector>
using namespace std;

vector<int> searchForRange(vector<int> array, int target) {
  int low = 0;
	int high = array.size()-1;
	int mid;
	vector<int> ans = {-1,-1};

	//First find the left extreme of the range.
	while(low <= high)
	{
		mid = (low+high)/2;

		if(array[mid] == target)
		{
			if(mid == 0 || array[mid-1] != target)
			{
				ans[0] = mid;
				break;
			}
			else if(array[mid-1] == target)
			{
				high = mid - 1;
			}
		}
		else if(target > array[mid]) low = mid + 1;
		else if(target < array[mid]) high = mid - 1;
	}

	//Second lets find the right extreme of the range.
	low = 0;
	high = array.size()-1;

	while(low <= high)
	{
		mid = (low+high)/2;

		if(array[mid] == target)
		{
			if(mid == array.size()-1 || array[mid+1] != target)
			{
				ans[1] = mid;
				break;
			}
			else if(array[mid+1] == target)
			{
				low = mid + 1;
			}
		}
		else if(target > array[mid]) low = mid + 1;
		else if(target < array[mid]) high = mid - 1;
	}
	return ans;
}
```
