# Generate Powerset

Given a set, generate its powerset.
```
Given A = [1,2,3].
Generate:
P(A) = [[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]
```

### Approach 1: Iterative Approach
```C++
#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array) {
  vector<vector<int>> ans ={{}};

	for(int i = 0; i < array.size(); i++)
	{
		// Remember that the loop condition in C++ gets re evaluated each time we excute the loop.
		// So we must calculate the size of the loop before hand!!!
		// This is not the case in Python.
    int end = ans.size();
		for(int j = 0; j < end; j++)
		{
      vector<int> a = ans[j];
      a.push_back(array[i]);
      ans.push_back(a);
		}
	}
	return ans;
}
```

### Approach 2: Recursive Approach

```C++
#include <vector>
using namespace std;

void generate_ps(vector<int> array, vector<int> set, vector<vector<int>> *ps, int n)
{
	if(n < 0) ps->push_back(set);
	else
	{
		// Ignore the last element
		generate_ps(array,set,ps,n-1);
		// Add the last element and continue
		set.push_back(array[n]);
		generate_ps(array,set,ps,n-1);
	}
}


vector<vector<int>> powerset(vector<int> array) {
	vector<vector<int>> ps;
	vector<int> set;
	generate_ps(array,set,&ps,array.size()-1);
  return ps;
}

```

### Approach 3: Bit Operation Magic
```C++
#include <vector>
#include <math.h>

using namespace std;

vector<vector<int>> powerset(vector<int> array) {
vector<vector<int>> ps;
for(int i = 0; i < pow(2,array.size()); i++)
{
	vector<int> set;
	for(int j = 0; j < array.size(); j++)
	{
		if(i&(1<<j)) set.push_back(array[j]);
	}
	ps.push_back(set);
}
  return ps;
}
```