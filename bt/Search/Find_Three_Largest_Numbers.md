# Find_Three_Largest_Numbers

Write a function that takes in an array of integers and returns a sorted array of the three largest integers in the input array. Note that the function should return duplicate integers if necessary; for example, it should return [10, 10, 12] for an input array of [10, 5, 9, 10, 12].

```
Sample Input: [141,1,17,-7,-17,-27,18,541,8,7,7]
Sample Output: [18,141,541] (sorted in increasing order)
```
### Naive Solution
Sort the array and return the last 3 digits.

* Time: O(NlogN) 
* Space: O(logN) (If Optimal Implementation of Quick Sort)
### Best Solution
1. Make an array of size 3, such that:
```
Array: [3rd largest number, 2nd largest number, 1st largest number].
```
2. Traverse the input array and:
3. Compare each value with the 3 entries in the array, if a greater value is found then shift all the other values in the array one position to the left and insert the new value. Else move on.

* Time: O(N) - As we traverse the array once.
* Space: O(1) - As an array of size 3 is maintained.
```C++
#include <vector>
using namespace std;


vector<int> sl(vector<int> ans, int key)
{
	if(ans[2] < key)
	{
		ans[0] = ans[1];
		ans[1] = ans[2];
		ans[2] = key;
	}
	else if(ans[1] < key)
	{
		ans[0] = ans[1];
		ans[1] = key;
	}
	else if(ans[0] < key)
	{
		ans[0] = key;
	}
	return ans;
}
vector<int> findThreeLargestNumbers(vector<int> array) {
	vector<int> ans = {-9999,-9999,-9999};
	for(int i = 0; i < array.size(); i++)
	{
		ans = sl(ans,array[i]);
	}
	return ans;
}
```