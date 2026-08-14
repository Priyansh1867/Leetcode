//Three Pointer approach
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //i , j ko last pr rakho 
        int i = m-1;
        int j = n-1;
        int k = m + n -1;

        // Compare elements from the back and place the larger one at index k
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
        // Copy any remaining elements from nums2 into nums1
        // (Remaining elements in nums1 are already sorted in their correct places)
        while(j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};
/*
Approach :- Brute Force , in this sorted arrays ko wapas sort kr rha hu isse time complexity optimised nhi h .
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>merged(n+m);
        for(int i=0 ; i<m ; i++)
        {
            merged[i] = nums1[i];
        }
        for(int i=0 ; i<n ; i++)
        {
            merged[m+i] = nums2[i];
        }
        sort(merged.begin() ,merged.end());

        for(int i=0 ; i<m+n ; i++)
        {
            nums1[i] = merged[i];
        }
    }
};
*/