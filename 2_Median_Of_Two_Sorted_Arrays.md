# Median of Two Sorted Arrays

There are two sorted arrays __nums1__ and __nums2__ of size __m__ and __n__ respectively. Find the median of the two sorted arrays.

You may assume nums1 and nums2 cannot be both empty.

### Example-1
```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```
### Example-2
```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

### __Naive Solution - O(m+n) | O(m+n)__

Merge the two sorted arrays using the simple merge logic. Let the size of the final merged array be __s = m + n__. If __s__ is even then return: __(A(s/2) + A(s/2 - 1))/2__, else return __A(s/2)__.

```C++
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged_list(nums1.size() + nums2.size(),0);
        
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] <= nums2[j])
            {
                merged_list[k]  = nums1[i];
                i++;
            }
            else
            {
                merged_list[k]  = nums2[j];
                j++;
            }
            k++;
        }
        while(i < nums1.size())
        {
            merged_list[k]  = nums1[i];
            i++;
            k++;
        }
        while(j < nums2.size())
        {
            merged_list[k]  = nums2[j];
            j++;
            k++;
        }
        
        double median;
        int size = nums1.size() + nums2.size();
        if(size%2 == 0) median = (float)(merged_list[size/2] + merged_list[size/2 -1])/2;
        else median = (float)merged_list[size/2];
        return median;
    }
```
---
