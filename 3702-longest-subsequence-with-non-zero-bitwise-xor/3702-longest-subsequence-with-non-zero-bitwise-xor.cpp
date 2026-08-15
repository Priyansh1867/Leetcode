class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool allzero = true;

        // Compute total XOR of the array and check if any non-zero element exists
        for(int &x : nums)
        {
            ans = ans ^ x;
            if(x != 0)
            {
                allzero = false;
            }
        }
        // Case 1: If all elements are 0, every subsequence XORs to 0
        if(allzero) return 0;

        // Case 2: If total XOR != 0, take the entire array (length n)
        // Case 3: If total XOR == 0 (with at least one non-zero element), 
        // removing any single non-zero element leaves a non-zero XOR (length n - 1)
        return ((ans == 0) ? n-1 : n);
    }
};