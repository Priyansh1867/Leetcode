class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0 , start = 0 , end = n-1;
        //(end = n-1) tk hi chalega
        while(i <= end)
        {
            if(nums[i] == 2)
            {
                swap(nums[i] , nums[end]);
                end--;
                // Do not increment 'i' here because the swapped element 
                // from 'end' has not been inspected yet.
            }
            else if(nums[i] == 0)
            {
                swap(nums[i] , nums[start]);
                start++;
                i++;
                
            }
            else
            {
                i++;
            }
        }
    }
};