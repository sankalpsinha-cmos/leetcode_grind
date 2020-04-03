# Longest Substring Without Duplicate

Write a function that takes in a string and that returns its longest substring without duplicate characters. Assume that there will only be one longest substring without duplication.

```
Sample Input: 'clementisacap'
Sample Output:  'mentisac'
```

### NAIVE IDEA 
1. Generate all the sub-strings of the given string.
2. Now use a set to eliminate all the sub-strings that have duplicate characters.
3. Return the longest sub-string from this set.

### NAIVE Time-Space Complexity
* It takes O(N^2) time to generate all the sub-strings of a string of size 'n'.
* There will be 2^n sub-strings for a string of size 'n'.
* Assuming the average size of each substring is 'd'.
* Then it will take O(2^n*d) time to generate all the unique-sub-strings.
* So overall it will take O(2^n*d) time, which is exponential.


``` C++
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> printAllSubstrings(string str)
{
	vector<string> allSubStrings;
	int size = 0;
	while(size < str.size())
	{
		for(int i = 0; i < str.size() - size; i++)
		{
			allSubStrings.push_back(str.substr(i,size+1));
		}
		size++;
	}
	return allSubStrings;
}

vector<string> getAllUniqueSubStrings(vector<string> allSubstrings)
{
	vector<string> allUniqueSubStrings;
	for(int i = 0 ; i < allSubstrings.size(); i++)
	{
		set<char> map;
		bool unique = true;
		for(int j = 0; j < allSubstrings[i].size(); j++)
		{
			auto itr = map.find(allSubstrings[i][j]);
			if(itr == map.end()) map.insert(allSubstrings[i][j]);
			else
			{
				unique = false;
				break;
			}
		}
		if(unique) allUniqueSubStrings.push_back(allSubstrings[i]);
	}
	return allUniqueSubStrings;
}

string longestSubstringWithoutDuplication(string str) {
 int len = 0;
	string longest;
	vector<string> allSubStrings = printAllSubstrings(str);
	vector<string> allUniqueSubStrings = getAllUniqueSubStrings(allSubStrings);
	for(auto itr = allUniqueSubStrings.begin(); itr != allUniqueSubStrings.end(); itr++)
	{
		string a = *itr;
		if(a.size() > len)
		{
			len = a.size();
			longest = a;
		}
	}
  return longest;
}
```
### BEST IDEA

1. Keep a variable called start, that keeps track of the start of the longest substring without duplicates, initially start = 0;
2. Make a hash map that stores a character and its position in the string. This way we keep track of when we last saw a given character.
3. Make an empty string that stores the current longest substring without duplicates.
4. Traverse through the string. Using a variable 'i'. 'i' will point to the end of the longest substring without duplicates, and do:
   * If str[i] isn't in the map then push the pair {str[i],i} into the map.
   * Else if str[i] is in the map then: start = max(start, last_seen_position_of(str[i]) + 1). Then also update the last_seen_position_of(str[i]) to 'i'.
   * Now check if 'i - start > ans.size()', if yes then store the new string into ans, else move on.
5. Now after you have traversed the entire string and exit the loop return ans.

### Time Complexity: O(N) - As we just traverse the whole string once and at each step just do a O(1) hash table lookup or insertion and some simple calculations.
### Space Complexity: O(N) - O(min(N,A)) - Where 'N' is the size of the input string and 'A' is the no of unique characters in the string.
```
Eg: for str = 'aaaaaaaaaaaa' the space complexity is O(1) while for str='abcdefgh' the space complexity is O(N).
```

```C++

#include <map>
#include <iostream>
using namespace std;

string longestSubstringWithoutDuplication(string str) {
  map<char,int> m;
	int start = 0;
	string ans = "";
	for(int i = 0; i < str.size(); i++)
	{
		auto itr = m.find(str[i]);
		if(itr == m.end())
		{
			m.insert({str[i],i});
		}
		else
		{
			start = max(start, itr->second + 1);
			itr->second = i;
		}
		if(i - start + 1 > ans.size())
		{
			ans.clear();
			for(int j = start; j <= i; j++)ans.push_back(str[j]);
		}
	}
	return ans;
}
```