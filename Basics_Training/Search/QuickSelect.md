# QuickSelect

Write a function that takes in an array of distinct integers as well as an integer k and returns the kth smallest number in that array in linear time, on average. The array could be sorted, but isn't necessarily so.
```
Sample Input: [8,5,2,9,7,6,3],3
Sample Output: 5
```
### THE CORE IDEA



```C++
#include <vector>
using namespace std;

int helper(vector<int> *array, int low, int high)
{
	int pivot = high;
	int i = low;
	int j = low - 1;
	for(; i < high; i++)
	{
		if(array->at(i) < array->at(pivot))
		{
			swap(array->at(++j),array->at(i));
		}
	}
	swap(array->at(++j),array->at(pivot));
	return j;
}

int quickselect(vector<int> array, int k) {
	int low = 0;
	int high = array.size()-1;
  int pivot_index = helper(&array,low,high);
	while(pivot_index != k-1)
	{
		if(pivot_index > k-1) pivot_index = helper(&array,low,pivot_index - 1);
		if(pivot_index < k-1) pivot_index = helper(&array,pivot_index + 1,high);
	}
	return array[k-1];
}
```
