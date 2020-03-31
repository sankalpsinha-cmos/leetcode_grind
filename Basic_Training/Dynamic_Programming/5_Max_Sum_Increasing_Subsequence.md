# Max Sum Increasing Subsequence

Given an non-empty array of integers, write a function that returns an array of length 2. The first element in the output array should be an integer value representing the greatest sum that can be generated from a strictly-increasing subsequence in the array. The second element should be an array of the numbers in that subsequence. A subsequence is defined as a set of numbers that are not necessarily adjacent but that are in the same order as they appear in the array. Assume that there will only be one increasing subsequence with the greatest sum.

### Example 1
```
Sample input: [10, 70, 20, 30, 50, 11, 30]
Sample output: 110, [10, 20, 30, 50]
```
### __Best Solution O(N^2) | O(N)__

We are trying to find the a subsequence in the given array that is:
* Strictly Increasing
* Has the maximum sum

We maintain another array that holds the max sum strictly increasing sub sequence, called __msis__

notice that at each element of the array we have the following __2__ possibilities:
* The current element is the max sum increasing subsequence. (Base Case)
* The current element + the some subsequence whose last element is smaller than the current element.

We take the max of these __2__ possibilites.

__msis(i) = max(msis(i) , msis(j) + array(i))__

Note that we initialize __msis = array__. As in the base case every element on its own will form a strictly increeasing subsequence.

As we only store the __max_sum__ in the __msis__ array. We can use simple backtracking to generate the sub-sequence that produced __max_sum__

```C++
vector<vector<int>> backtrack(vector<int> array, vector<int> msis, int max_msis_idx)
{
	int max_sum = msis[max_msis_idx];
	vector<vector<int>> ans;
	ans.push_back(vector<int>{max_sum});
	vector<int> seq;
	int i = max_msis_idx;
	while(max_sum != 0 && i >= 0)
	{
			if(msis[i] == max_sum)
			{
				max_sum -= array[i];
				seq.push_back(array[i]);
			}
		i--;
	}
	reverse(seq.begin(),seq.end());
	ans.push_back(seq);
	return ans;
}

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
	vector<int> msis = array;
	int max_msis_idx = 0;
	for(int i = 0; i < array.size(); i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(array[j] < array[i])
			{
				msis[i] = max(msis[i],array[i] + msis[j]);
				if(msis[i] > msis[max_msis_idx]) max_msis_idx = i;
			}
		}
	}
	return backtrack(array,msis,max_msis_idx);
}

```
---