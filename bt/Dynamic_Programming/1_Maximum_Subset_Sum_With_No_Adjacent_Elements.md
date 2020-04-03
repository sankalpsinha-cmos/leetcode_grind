# Maximum_Subset_Sum_With_No_Ajacent_Elements

Write a function that takes in an array of positive integers and returns an integer representing the maximum sum of non-adjacent elements in the array. If a sum cannot be generated, the function should return 0.

### Example 1
```
Sample input: [75, 105, 120, 75, 90, 135]
Sample output: 330 (75, 120, 135)
```
### __Best Solution O(N) | O(N)__
The main Idea is:

Notice that mss([75, 105, 120, 75, 90, 135]) = max(135 + mss([75, 105, 120, 75]), mss([75, 105, 120, 75, 90]))

If you draw the recursion tree for this problem you will find many repeating sub-problems. Hence we have statisfied the overlapping sub-problem nature needed to detect that this is a dynamic programming question.

So, we maintain an array called __max_sums__, that keeps track of the __Maximum_Subset_Sum_With_No_Ajacent_Elements__ up till each element. We will apply the bottom-up approach.

```
array:		[75, 105, 120, 75, 90, 135]
max_sum:	[75, 105, 195, 195, 285, 330]

formula:	max_sum[i] = max(array[i] + max_sum[i-2], max_sum[i-1]);
			for all i >=2 && i < array.size().
```
So either take the current element and add it to the max_sum we got when its neighbour is excluded OR discard the element and just take the max_sum we got when considering its neighbour.

For i = 0 and i = 1, the logic is simple:
1. If the array is empty return 0.
2. If the array size is 1, then return the only element.
3. If the array size is 2, then return the max of the two elements.
 
```C++
#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
	if(array.size() == 0) return 0;
	else if(array.size() == 1) return array[0];
	else if(array.size() == 2) return max(array[0],array[1]);
	else
	{
		int max_index = 2;
		vector<int> max_sum(array.size(),-1);
		max_sum[0] = array[0];
		max_sum[1] = max(array[0],array[1]);
		for(int i = 2; i < max_sum.size(); i++)
		{
			max_sum[i] = max(array[i] + max_sum[i-2], max_sum[i-1]);
			if(max_sum[i] > max_sum[max_index]) max_index = i;
		}
		return max_sum[max_index];
	}
}
```
---