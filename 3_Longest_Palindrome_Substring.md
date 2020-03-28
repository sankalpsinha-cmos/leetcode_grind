# Longest Palindrome Substring

Given a string __s__, find the longest palindromic substring in __s__. You may assume that the maximum length of s is 1000.

### Example-1
```
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
```
### Example-2
```
Input: "cbbd"
Output: "bb"
```
#### __Best Solution - O(N^2) | O(1)__

A palindrome can have 2 types of centers
* In the string "babad" the palindrome string "bab" has the the letter __a__ as the centre.
* In the string "cbbd" the palindrome string "bb" has the __space__ right after the letter __b__ as the centre.

So we take the two cases and at each letter of the given string check is a palindome is present. We keep track of the longest palindrome found.

### __Time and Space Complexity Explaination__
#### Time 
We iterate through the array one element at a time, this takes __O(N)__ time.
Further at each element in the array we expand as:
* Assuming the element is the center of the palindrome.
* Assuming the space right next to the element is the center of the palindrome.

Each of the above mentioned expansion can take a max of __O(N)__ time.

Hence the total time complexity of __O(2N^2)__ = __O(N^2)__ time.

#### Space

As we just use some local variables the space complexity is __O(1)__.
```C++
string longestPalindrome(string s) {
        // Keep track of the longest palindrome found.
        int left_index = 0;
        int right_index = 0;
        int size = 0;
        // The string to store the longest palindrome.
        string lps;
        
        // Assuminng each letter is the centre of a palindrome
        for(int i = 0; i < s.size(); i++)
        {
            int left = i - 1;
            int right = i + 1;
            while(left >=0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }
            if(right - left > size)
            {
                size = right - left;
                left_index = left + 1;
                right_index = right - 1;
            }
        }
        
        // Assuming the space just right to a letter is the centre of a palindrome
        for(int i = 0; i < s.size(); i++)
        {
            int left = i;
            int right = i + 1;
            while(left >=0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }
             if(right - left > size)
            {
                size = right - left;
                left_index = left + 1;
                right_index = right - 1;
            }
        }
        // Construct the longest palindrome using the indexes we kept track of
        for(int i = left_index; i <= right_index; i++)
        {
            lps.push_back(s[i]);
        }
        return lps;
    }
```
---