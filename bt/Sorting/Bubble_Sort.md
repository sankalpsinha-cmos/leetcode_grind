# Bubble Sort
```
Write a function that takes in an array of integers and returns a sorted version of that array. Use the Bubble Sort algorithm to sort the array.
```
```
Sample Input: [8,5,2,9,5,6,3]
Sample Output: [2,3,5,5,6,8,9]
```
* Time: O(N^2) | Θ(N^2) | Ω(N^2)
* Space: O(1)
```C++
//Code: (Optimised to stop if the array becomes sorted after some pass)

#include <vector>
using namespace std;
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

vector<int> bubbleSort(vector<int> array) {
  for(int i = array.size(); i >= 0; i--)
	{
		bool swap_occured = false;
		for(int j = 1; j < i; j++)
		{
			if(array[j-1] > array[j])
			{
				swap(&array[j-1],&array[j]);
				swap_occured = true;
			}
		}
		if(!swap_occured) break;
	}
	return array;
}
```