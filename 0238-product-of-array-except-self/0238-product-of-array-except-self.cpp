class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n);
        vector<int>suf(n);
        vector<int>ans(n);

        pre[0] = nums[0];
        for(int i=1 ; i<n ; i++)
        {
            pre[i] = pre[i-1] * nums[i];
        }
        suf[n-1] = nums[n-1];
        for(int i=n-2 ; i>=0 ; i--)
        {
            suf[i] = suf[i+1] * nums[i];
        }
        for(int i=0; i<n ; i++)
        {
            int left_product = (i == 0) ? 1 : pre[i-1];
            int right_product = (i == n-1) ? : suf[i+1];
            ans[i] = left_product * right_product; 
        }
        return ans;
    }
};