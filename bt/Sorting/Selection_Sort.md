# Selection Sort
```
Write a function that takes in an array of integers and returns a sorted version of that array. Use the Selection Sort algorithm to sort the array.
```
```
Sample Input: [8,5,2,9,5,6,3]
Sample Output: [2,3,5,5,6,8,9]
```
```
Time: O(N^2)
Space: O(1)
```
```
Useful: Selection Sort only makes O(n) swaps! So its great when disk operations are costly.
```
```C++
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

vector<int> selectionSort(vector<int> array) {
  for(int i = 0; i < array.size(); i ++)
	{
		int min = i;
		int j = i + 1;
		for(;j < array.size(); j++)
		{
			if(array[j] < array[min])
			{
				min = j;
			}
		}
		swap(&array[min],&array[i]);
	}
	return array;
}
```