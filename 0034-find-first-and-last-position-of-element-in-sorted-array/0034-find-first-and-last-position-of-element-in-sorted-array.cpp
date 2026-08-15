class Solution {
    //lower bound condition :- nums[mid] >= target 
    //upper bound condition :- nums[mid] > target
    int lowerbound(vector<int>&nums , int n , int target)
    {
        int start = 0 , end = n-1;
        int index = n;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] >= target)
            {
                index = mid;
                end = mid-1;
            }
            else 
            {
                start = mid + 1;
            }
        }
        return index;
    }
    int upperbound(vector<int>&nums , int n , int target)
    {
        int start = 0 , end = n-1;
        int index = n;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] > target)
            {
                index = mid;
                end = mid-1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerbound(nums , n , target);
        int ub = upperbound(nums , n , target);
        
        if(lb == ub || nums[lb] != target) return {-1 , -1};
        else
        {
            return {lb , ub-1};
        }
    }
};