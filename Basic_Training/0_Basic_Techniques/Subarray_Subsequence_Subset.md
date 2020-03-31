# Understanding SubArray, SubSequence and SubSet

## SubArray:
A sub-Array is a contigeous slice of the orginal array.

```
Let A = [1,2,3].

Then the valid sub-arrays are:
[1], [2], [3], [1,2], [2,3] and [1,2,3].

Notice that each valid sub-array is a contigeous slice of the orginal array.
```
### No of sub-array for an array with 'N' elements: (N(N+1))/2

```C++
void generate_all_subarrays(vector<int> *array, vector<vector<int>> *subarrays)
{
	int size = 0; // Define the size of the subarray.
	while(size < array->size()) // Generate sub-arrays from size 0 to n-1.
	{
	    int start = 0; // Set the start point of the sub-array to first element
		for(; start < array->size(); start++) // Make sure that each element has a chance to be the start of the sub-array.
		{
			int end = start + size; // Calcultae the end point of the sub-array.
			if(end < array->size()) // If the end point is inside the array bounds then it is a valid sub-array.
			{
				vector<int> subarray;
				for(int i = start; i <= end; i++) // Copy the valid sub-array.
				{
					subarray.push_back(array->at(i));
				}
				subarrays->push_back(subarray); // Push this sub-array onto the set of all sub-arrays generated.
			}
		}
		size++; // Now increase the size of the sub-array being generated.
	}
}
```
---
## SubString
A Sub-String is a contigeous slice of the original string.
It is the same as the sub-array in the context of a string.
```
Let s = 'abc'

Then its valid substrings are:
['a', 'b', 'c', 'ab', 'bc', 'abc']

Notice that each valid sub-string is a contigeous slice of the orginal string.
```
### No of sub-strings for a string with 'N' elements: (N(N+1))/2
```C++

```
