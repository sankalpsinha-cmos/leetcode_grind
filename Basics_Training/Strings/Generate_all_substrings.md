# Generate All Sub-Strings of a String

### Basic Idea:
1. Define a size variable that controls the size of the substring being generated.
2. Make size go from [1 to len(str)].
3. Make i go from [0 to len(str) - size].
4. use str.substr(i,size) to extract the substring. In substr 'i' is the starting index and 'size' is the no of characters to include in the substring.

### Time and Space Complexity:
* Time: O(N^2)
* Space: O(1) - If not storing.
* Space: O(2^n) - If storing.

### Code
```C++
vector<string> printAllSubstrings(string str)
{
	vector<string> allSubStrings;
	int size = 1;
	while(size <= str.size())
	{
		for(int i = 0; i <= str.size() - size; i++)
		{
			allSubStrings.push_back(str.substr(i,size));
		}
		size++;
	}
	return allSubStrings;
}
```