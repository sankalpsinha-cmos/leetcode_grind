# Max Profit with k Transactions

1. You are given an array of integers representing the prices of a single stock on various days (each index in the array represents a different day).
2. You are also given an integer k, which represents the number of transactions you are allowed to make.
3. One transaction consists of buying the stock on a given day and selling it on another, later day.
4. Note that you can only hold 1 share of the stock at a time; in other words, you cannot buy more than 1 share of the stock on any given day, and you cannot buy a share of the stock if you are still holding another share.
5. Note that you also don't need to use all k transactions that you're allowed.

Write a function that returns the maximum profit that you can make buying and selling the stock, given k transactions.
### Example 1
```
Sample input: [5, 11, 3, 50, 60, 90], 2
Sample output: 93 (Buy: 5, Sell: 11; Buy: 3, Sell: 90)

```

### __Best Solution O(kn^2) | O(nk)__
This is a tricky problem. As you might have suspected we will make a matrix with the no.of transactions as its rows and the prices array as its columns.

The main idea is that at any point in the table we have 2 choices:
1. Ignore to sell on this day and just keep the previous days profit.
2. Sell on this day and see if you make more profit than previous day.

```
so we are maximizing:

max(mat[t][d-1] , prices[d] + max(-prices[x] + profit[t-1][x]) for x in [0,d) )
        ^           ^                   ^               ^
        |           |                   |               |
    Don't Sell   Sell Now       Must have Bought Here   Carry forward previous profit
        
t = transaction index, d = prices index
```

We can build the following table
<table border="1" cellpadding="0" cellspacing="0" width="600" >
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; k/prices</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 5</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 11</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 3</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 50</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 60</td>
        <td height="20%" width="10%" style="text-align: center">&nbsp; 90</td>
	</tr>
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 0</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 0</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 0</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 0</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 0</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 0</td>
        <td height="20%" width="10%" style="text-align: center">&nbsp; 0</td>
	</tr>
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 1</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 0</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 6</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 6</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 47</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 57</td>
        <td height="20%" width="10%" style="text-align: center">&nbsp; 87</td>
	</tr>
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 2</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 0</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 6</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 6</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 53</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 63</td>
        <td height="20%" width="10%" style="text-align: center">&nbsp; 93</td>
	</tr>
</table>

### __Optimizing the above solution__

#### Optimizing Timr Complexity
We notice that the current time complexity is __O(kn^2)__.

This can be reduced if we notice that the operation: __max(-prices[x] + profit[t-1][x]) for x in [0,d) )__. Has repeating calculations, check yourself for when k:2 and day: 60 and k:2 and day: 90.

We can reduce these repeating calculations if we store the values somewhere. Bringing the complexity down to __O(kn)__.

#### Optimizing Timr Complexity
We store a table from 0 to k transactions. But if you look at the formula closely, to fill the __k__ th row we only need the __k__ th and the __k-1__ th row.

So it is possible to make just have table effectivel of size 2 and reduce the space complexity of the algorithm from __O(nk)__ to __O(n)__.

### __Solution with O(kn^2) Time Complexity__
```C++
#include <vector>
using namespace std;

int max_of_seq(vector<int> prices, vector<vector<int>> profit, int t, int d)
{
	int max_sum = INT_MIN;
	for(int x = 0; x < d; x++)
	{
		int sum = profit[t-1][x] - prices[x];
		if(sum > max_sum) max_sum = sum;
	}
	return max_sum;
}

int maxProfitWithKTransactions(vector<int> prices, int k) {
  vector<vector<int>> profit(k+1,vector<int>(prices.size(),0));

	for(int t = 1; t < k+1 ; t++)
	{
		for(int d = 1; d < prices.size(); d++)
		{
			profit[t][d] = max(profit[t][d-1], prices[d] + max_of_seq(prices,profit,t,d));
		}
	}
	int ans = 0;
	for(int t = 0; t < k+1 ; t++)
	{
		for(int d = 0; d < prices.size(); d++)
		{
			ans = profit[t][d];
		}
		cout<<endl;
	}
	return ans;
}
```