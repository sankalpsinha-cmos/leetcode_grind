# Longest Common Subsequence

Implement a function that returns the longest subsequence common to two given strings. A subsequence is defined as a group of characters that appear sequentially, with no importance given to their actual position in a string. In other words, characters do not need to appear consecutively in order to form a subsequence. Assume that there will only be one longest common subsequence.

### __Example 1__
```
Sample input: "ZXVVYZW", "XKYKZPW"
Sample output: ["X", "Y", "Z", "W"]
```
### Best Solution O() | O()
```
Take the strings: str1 = 'abc' and str2 = 'zxc'
LCS('abc','zxc) = c + LCS('ab','zx')
LCS('ab','zx') = max(LCS('ab','z') , LCS('a','zx'), LCS('a','z'))
LCS('ab','z') = max(LCS('ab','') , LCS('a','z') , LCS('a',''))
LCS('a','zx') = max(LCS('a','z') , LCS('','zx') , LCS('','z'))
LCS('a','z') = max(LCS('a','') , LCS('','z') , LCS('',''))
LCS('ab','') = '' [Base Case]
LCS('a','z') = max(LCS('a','') , LCS('','z') , LCS('',''))
LCS('a','') = '' [Base Case]
```
Draw out the recursion tree and you can notice that in this recursion there are many repeating sub-problems So we should apply dynamic programming to solve this question.

Lets make table, with the size of: __str2 x str1__

<table border="1" cellpadding="0" cellspacing="0" width="600" >
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; str1/str2</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; BC(-)</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; a</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; b</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; c</td>
	</tr>
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; BC(-)</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
	</tr>
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; z</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
	</tr>
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; x</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
	</tr>
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; c</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="10%" width="10%" style="text-align: center">&nbsp; -</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; c</td>
	</tr>
</table>

```C++
#include <vector>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2)
{
	str1 = " " + str1;
	str2 = " " + str2;
	vector<vector<vector<char>>> lcs;
	for(int i = 0; i < str2.size(); i++)
	{
		lcs.push_back(vector<vector<char>>{});
		for(int j = 0; j < str1.size(); j++)
		{
			lcs[i].push_back(vector<char>());
		}
	}

	for(int i = 1; i < str2.size(); i++)
	{
		for(int j = 1; j < str1.size(); j++)
		{
			if(str1[j] == str2[i])
			{
				lcs[i][j] = lcs[i-1][j-1];
				lcs[i][j].push_back(str1[j]);
			}
			else
			{
				vector<char> t = lcs[i-1][j].size() > lcs[i][j-1].size()? lcs[i-1][j]:lcs[i][j-1];
				t = lcs[i-1][j-1].size() > t.size()? lcs[i-1][j-1]:t;
				lcs[i][j] = t;
			}
		}
	}
  	return lcs[lcs.size()-1][lcs[lcs.size()-1].size()-1];
}

```
---