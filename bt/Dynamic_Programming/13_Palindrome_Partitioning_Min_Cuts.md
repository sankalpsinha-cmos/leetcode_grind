# Palindrome Partitioning Min Cuts

Given a non-empty string, write a function that returns the minimum number of cuts needed to perform on the string such that each remaining substring is a palindrome. A palindrome is defined as a string that is written the same forward as backward. Note that single-character strings are palindromes.

### Example 1
```
Sample input: "noonabbad"
Sample output: 2 ("noon | abba | d")
```

### __Solution O(N^3) | O(N^2)__

The main idea is, we go from (0 - str.size()) and at each index calculate the min cuts needed to break str into palindromes.

So at at any index i while building this array we have 2 choices:
1. min_cut[i] = min_cut[i - 1].
2. min_cut[i] = 1 + any palindrome string you find from (0 to i-1).

And we actually end up taking the minnimum of these 2 values hence,
__min_cut[i] = min(1,2)__

```C++
#include <vector>
using namespace std;

bool isPalindrome(string str, int start, int end)
{
	if(start == end) return true;
	while(start <= end)
	{
		if(str[start] != str[end]) return false;
		start++;
		end--;
	}
	return true;
}

int palindromePartitioningMinCuts(string string) {
  vector<int> min_cut(string.size(),INT_MAX);
	for(int i = 0; i < string.size(); i++)
	{
		if(isPalindrome(string,0,i)) min_cut[i] = 0;
		else
		{
			min_cut[i] = min_cut[i-1] + 1;
			int j = i - 1;
			for(; j >= 0; j--)
			{
				if(isPalindrome(string,j,i))
				{
					min_cut[i] = min(min_cut[i],min_cut[j-1] + 1);
				}
			}
		}
	}
  return min_cut[min_cut.size()-1];
}

```