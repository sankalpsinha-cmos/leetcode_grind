# Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target. You may assume that each input would have exactly one solution, and you may not use the same element twice.

#### Example
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

#### __Naive Solution - O(N^2) | O(1)__

Take two pointers and go through the array and check every pair of numbers. Find the two numbers that add up and return their incides.

```C++
ector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == target) return vector<int> {i,j};
        }
    }
    return vector<int>();
    }
```
---

#### __Best Solution - O(N) | O(N)__

As we are essentially solving __X + A(i) = T__
Make a unordred_map and for each element __A(i)__ check if __T - A(i)__ is present in the map. If __NO__ then add __A(i)__ to the map. If __YES__ then return respective indices.

```C++
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            auto itr = m.find(target - nums[i]);
            if(itr == m.end()) m.insert({nums[i],i});
            else return vector<int> {itr->second,i};
        }
        return vector<int>();
    }
```
---