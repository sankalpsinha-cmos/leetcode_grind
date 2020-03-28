# Smallest Substring Containing
You are given two non-empty strings: a big string and a small string. Note that:
1. The substring can contain other characters not found in the small string.
2. The characters in the substring don't have to be in the same order as they appear in the small string.
3. If the small string has duplicate characters, the substring has to contain those duplicate characters (it can also contain more, but not fewer).

Write a function that returns the smallest substring in the big string that contains all of the characters found in the small string. 

```
Sample input: "abcd$ef$axb$c$", "$$abf"
Sample output: "f$axb$"

Basically we are trying to find the smallest substring (contigious subarray) of the bigString that has all the elements of the smallString. See the rules.
```
### __Naive Idea (My Idea) O(N^2) | O(M)__
The naive idea is as follows:
1. Make a hash map of the smallString.
2. We will make all possible contigeous subarrays of the bigString using 2 for loops.
3. If a generated contigeous subarrays  has all the elements as seen in the hash map, we save it and its size only if its the smallest we have seen till now.
4. After the for loop end we return the saved smallest substring.

Note |bigString| = n and |smallString| = m
```C++
#include <unordered_map>
using namespace std;

string smallestSubstringContaining(string bigString, string smallString) {
	unordered_map<char,int> map;
	unordered_map<char,int> cmap;
	int min_size = INT_MAX;
	string ans;
	for(int i = 0; i < smallString.size(); i++)
	{
		auto itr = map.find(smallString[i]);
		if(itr == map.end()) map.insert({smallString[i],1});
		else itr->second++;
	}
	
	for(int i = 0; i < bigString.size(); i++)
	{
		cmap = map;
		int j = i;
		string subs;
		for(; j < bigString.size(); j++)
		{
			if(cmap.empty()) break;
			auto itr = cmap.find(bigString[j]);
			if(itr != cmap.end())
			{
				itr->second--;
				if(itr->second == 0) cmap.erase(itr);
			}
			subs += bigString[j];
		}
		if(cmap.empty() && subs.size() < min_size)
		{
			min_size = subs.size();
			ans = subs;
		}
	}
  return ans;
}
```
### __Optimal Solution O(N) | O(M)__ 




```C++
#include <unordered_map>
using namespace std;

string smallestSubstringContaining(string bigString, string smallString) {
  unordered_map<char,int> map;
	/* Keep Track of a valid string and its size. */
	int min_len = INT_MAX;
	int left_idx = 0;
	int right_idx = 0;
    string ans;
	/* Flag to make sure we at leaast found 1 valid substring, if not we return blank string at the end.*/
	bool found_at_least_one_valid_string = false;
	/* Create a hash map of the smallString. */
	for(int i = 0; i < smallString.size(); i++)
	{
		auto itr = map.find(smallString[i]);
		if(itr == map.end()) map.insert({smallString[i],1});
		else itr->second++;
	}
	// counter for unique elements in the smallString.
	int c = map.size();
	// Left and right pointers
	int left = 0;
	int right = 0;
	while(right < bigString.size())
	{
		while(right < bigString.size() && c > 0)
		{
			auto itr = map.find(bigString[right]);
			if(itr != map.end())
			{
				itr->second--;
				if(itr->second == 0) c--;
			}
			right++;
		}
		while(c <= 0)
		{
			found_at_least_one_valid_string = true;
			auto itr = map.find(bigString[left]);
			if(itr != map.end())
			{
				itr->second++;
				if(itr->second > 0) c++;
			}
			left++;
		}
		int size = right - left - 1;
		if(size < min_len)
		{
			min_len = size;
			left_idx = left - 1;
			right_idx = right -1;
		}
	}
	for(int i = left_idx; i <= right_idx; i++) ans.push_back(bigString[i]);
	if(found_at_least_one_valid_string) return ans;
    return "";
}
```
---