# No of Ways To Make Change

Given an array of positive integers representing coin denominations and a single non-negative integer representing a target amount of money, implement a function that returns the number of ways to make change for that target amount using the given coin denominations. Note that an unlimited amount of coins is at your disposal.

### Example 1
```
Sample input: 6, [1, 5]
Sample output: 2 (1x1 + 1x5 and 6x1)
```
### __Best Solution O() | O()__


```C++
#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
	vector<int> ways(n+1,0);
	ways[0] = 1;
	sort(denoms.begin(),denoms.end());
	for(int i = 0; i < denoms.size(); i++)
	{
		for(int j = 0; j < ways.size(); j++)
		{
			if(denoms[i] <= j) ways[j] += ways[j-denoms[i]];
		}
	}
	return ways[n];
}
```
---