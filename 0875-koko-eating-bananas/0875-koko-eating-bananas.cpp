class Solution {
public:
    // Helper function to check if speed k is sufficient
    bool canfinish(const vector<int>&piles , int h , int k)
    {
        long long totalHours = 0;
        for(int pile : piles)
        {
            // Equivalent to ceil(pile / (double)k) using integer arithmetic
            totalHours += (pile + k - 1LL) / k;
        }
        return totalHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin() , piles.end());
        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(canfinish(piles , h , mid))
            {
                ans = mid;         // Valid speed, try finding a smaller one
                high = mid - 1;
            }
            else
            {
                low = mid + 1;     // Too slow, increase speed
            }
        }
        return ans;
    }
};