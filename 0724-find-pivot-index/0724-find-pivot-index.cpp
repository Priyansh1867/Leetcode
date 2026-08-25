class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum = 0;
        int sum = accumulate(nums.begin() , nums.end() , 0);

        for(int i=0 ; i<nums.size() ; i++)
        {
            if(2*leftsum + nums[i] == sum) return i;
            leftsum += nums[i];
        }
        return -1;
    }
};