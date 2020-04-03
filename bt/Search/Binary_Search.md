# Binary Search

Write a function that takes in a sorted array of integers as well as a target integer. The function should use the Binary Search algorithm to find if the target number is contained in the array and should return its index if it is, otherwise -1.
```
Sample Input: [0,1,21,33,45,45,61,71,72,73], target: 33
Sample output: 3
```
### Time:  O(logN) | Θ(logN) | Ω(LogN)
### Space: O(1)

```C++
int binarySearch(vector<int> array, int target) {
  int low = 0;
	int high = array.size() - 1;
	int index = -1;
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(array[mid] == target)
		{
			index = mid;
			break;
		}
		else if(target > array[mid])
		{
			low = mid +1;
		}
		else if(target < array[mid])
		{
			high = mid - 1;
		}
	}
	return index;
}
```