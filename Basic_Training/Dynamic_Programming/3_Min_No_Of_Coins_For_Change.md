# Min No OF Coins For Change

Given an array of positive integers representing coin denominations and a single non-negative integer representing a target amount of money, implement a function that returns the smallest number of coins needed to make change for that target amount using the given coin denominations. Note that an unlimited amount of coins is at your disposal. If it is impossible to make change for the target amount, return -1.

### __Example 1__
```
Sample input: 7, [1, 5, 10]
Sample output: 3 (2x1 + 1x5)
```
### __Best Solution O() | O()__


```C++
#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
	sort(denoms.begin(),denoms.end());
	vector<int> mnc(n+1,9999);
	mnc[0] = 0;
	for(int i = 0; i < denoms.size(); i++)
	{
		for(int j = 0; j < mnc.size(); j++)
		{
			if(denoms[i] <= j)
			{
				mnc[j] = min(mnc[j],mnc[j-denoms[i]] + 1);
			}
		}
	}
  return mnc[n] >= 9999?-1:mnc[n];
}
```
---