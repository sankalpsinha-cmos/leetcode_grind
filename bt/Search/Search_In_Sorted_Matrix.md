# Search in a sorted matrix.
```
You are given a two-dimensional array (matrix) of distinct integers where each row is sorted and each column is also sorted. The matrix does not necessarily have the same height and width. You are also given a target number, and you must write a function that returns an array of the row and column indices of the target number if it is contained in the matrix and [-1, -1] if it is not contained in the matrix.
```
```
Notice: In a sorted matrix the rows are sorted in ascending order form left to right. While the columns are sorted in ascending order from top to bottom.
```
```
Sample Input:
[
[1,4,7,12,15,1000],
[2,5,19,31,32,1001],
[3,8,24,33,35,1002],
[40,41,42,44,45,1003],
[99,100,103,106,128,1004]
], Target: 44

Note: In this sample input the matrix has a size of 6x6. But that need not be the case always, generally the size can be M x N.

Sample Output: [3,3]
```
### BEST IDEA
1. Set a variable called row = 0.
2. Set a variable called col = matrix[row].size() - 1.
```
3. While(col >= 0 && row < matrix.size()) do:
	1. If(target > matrix[row][col])
      {
        row++;
        col = matrix[row].size()-1;
      }
  b: If(target < matrix[row][col])
      {
      col--;
      }
  c: If(target == matrix[row][col]) return vector<int>{row,col};
```
4: return vector<int>{-1,-1};

```C++
#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int> > matrix, int target) {
	int row = 0;
	int col = matrix[row].size()-1;
	while(row < matrix.size() && col >= 0)
	{
		if(matrix[row][col] > target)
		{
			col--;
		}
		else if(matrix[row][col] < target)
		{
			col = matrix[++row].size()-1;
		}
		else if(matrix[row][col] == target)return vector<int>{row,col};
	}
	return vector<int>{-1,-1};
}
```
