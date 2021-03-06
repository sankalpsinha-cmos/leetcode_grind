# Implement Merge Sort

```
BASIC BACKGROUND:

Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. See following C implementation for details.
```
```
ANALYSIS:

Rec Rel: T(N) = 2T(n/2) + O(N)

Where 2T(N/2) comes because the array is divided into 2 smaller subproblems.
O(N) comes from the time taken to merge to sorted arrays.

Time: O(NlogN)

Time complexity of Merge Sort is Theta(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and take linear time to merge two halves.

Space: O(N) - Same for all cases.
```
### Implementation using vector C++ STL
```
Implementation using vector and STL isn't like Implementation using array.
The standard way we learned in university.
We create a copy of the original vector called temp.
We use temp to do all the calculations and copy the results into the original array.

Always remember we must pass vectors using reference between functions otherwise they will be local to the function.
```
```C++
#include <vector>
using namespace std;

void merge(vector<int> *array, int low, int mid, int high, vector<int> *temp)
{
    // Notice here we don't create temp array and copy from the original. We use the temp vector and just play with the indexes.
	int i = low;
	int j = mid + 1;
	int k = low;
	while(i <= mid && j <= high)
	{
		if(temp->at(i) <= temp->at(j)) array->at(k++) = temp->at(i++);
		else array->at(k++) = temp->at(j++);
	}
	while(i <= mid) array->at(k++) = temp->at(i++);
	while(j <= high) array->at(k++) = temp->at(j++);
}

void ms(vector<int> *array, int low, int high, vector<int> *temp)
{
	if(low < high)
	{
		int mid = (low + high)/2;
		
		ms(temp,low,mid,array); // Use the temp array for the recursion and keep the original safe. Thats why we pass temp as array and array as temp.
		ms(temp,mid+1,high,array);  // Use the temp array for the recursion and keep the original safe. Thats why we pass temp as array and array as temp.
		merge(array,low,mid,high,temp); // Now pass the array and temp as expected.
	}
}

vector<int> mergeSort(vector<int> array) {
	if(array.size()<=1) return array;
	vector<int> temp = array;
	ms(&array,0,array.size()-1,&temp);
	return array;
}
```