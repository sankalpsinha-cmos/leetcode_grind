# Levenshtein Distance

Write a function that takes in two strings and returns the minimum number of edit operations that need to be performed on the first string to obtain the second string. There are three edit operations: insertion of a character, deletion of a character, and substitution of a character for another.

### Example 1
```
Sample input: "abc", "yabd"
Sample output: 2 (insert "y"; substitute "c" for "d")
```

### __Best Solution O(MN) | O(MN)__
The idea is to make a 2D matrix with the two strings serving as the rows and columns of the matrix.

We add a blank space and so that we can make the base case in the matrix.

Notice that the column with '-' and the row with '-' are the base cases.

Using the formula:
```C++
if(str1[i] == str2[j])
{
	// If the two alphabets are equal then the levenshtein distance is the same as that of the strings when these to alphabets are ignored.
	mat[i][j] = mat[i-1][j-1]
}
else
{
	// If the alphabets are non the same then the new levenshtein distance is the minimum of the three neighbouring blocks + 1.  
	mat[i][j] = min(min(mat[i-1][j] , mat[i][j-1]) , mat[i-1][j-1]) + 1
}
```

We can build the following table
<table border="1" cellpadding="0" cellspacing="0" width="600" >
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; str1/str2</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; BC(-)</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; y</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; a</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; b</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; d</td>
	</tr>
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; BC(-)</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 0</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 1</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 2</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 3</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 4</td>
	</tr>
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; a</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 1</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 1</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 1</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 2</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 3</td>
	</tr>
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; b</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 2</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 2</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 2</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 1</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 2</td>
	</tr>
	<tr>
		<td height="20%" width="10%" style="text-align: center">&nbsp; c</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 3</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 3</td>
		<td height="10%" width="10%" style="text-align: center">&nbsp; 3</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 2</td>
		<td height="20%" width="10%" style="text-align: center">&nbsp; 2</td>
	</tr>
</table>

```C++
using namespace std;

int levenshteinDistance(string str1, string str2) {
	string strr1 = " ";
	string strr2 = " ";
	strr1.append(str1);
	strr2.append(str2);
	str1 = strr1;
	str2 = strr2;
  vector<vector<int>> mat(str1.size()+1,vector<int>(str2.size()+1,0));
	for(int i = 0; i < mat[0].size(); i++)mat[0][i] = i;
	for(int i = 0; i < mat.size(); i++) mat[i][0] = i;
	for(int i = 1; i < mat.size(); i++)
	{
		for(int j19= 1; j < mat[i].size(); j++)
		{
			if(strr1[i] == strr2[j])
			{
				mat[i][j] = mat[i-1][j-1];
			}
			else
			{
				mat[i][j] = min(min(mat[i-1][j],mat[i][j-1]),mat[i-1][j-1]) + 1;
			}
		}
	}
  return mat[str1.size()][str2.size()];
}
```
---