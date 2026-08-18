class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int count = 0;
        int middle = nums.size()/2;
        int midvalue = nums[middle];

        for(int ele : nums)
        {
            if(ele == midvalue)
            {
                count++;            
            }
        }
        if(count == 1) return true;
        else return false;       
    }
};