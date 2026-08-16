class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //To maintain sliding window of the most recent k elements
        unordered_set<int>set;
    
        for(int i=0 ; i<nums.size() ; i++)
        {
            // If window size exceeds k, remove the element that fell out of range (i - k - 1)
            if(i > k)
            {
                set.erase(nums[i-k-1]);
            }
            // If the current number already exists in the current window of size k, duplicate found
            if(set.count(nums[i])) return true;

            // Add the current element into the window
            set.insert(nums[i]);
        }
        // No duplicate found within distance k
        return false;
    }
};