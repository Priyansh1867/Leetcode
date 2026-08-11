class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum  = 0;
        // 0 to k tak ka sum nikal lege
        for(int i=0; i<k ; i++)
        {
            sum += nums[i];
        }
        //ans me sum/k daalege taki average nikal sake aur (double ka use krege kyuki question me double bhi use ho rha h )
        double ans = sum / (double)k;
        // k to nums.size() tak chalega 
        for(int i=k ; i<nums.size() ; i++)
        {
            // sum nikalo k se aage tak ka 
            sum += nums[i];
            // prurana wala ek minus krte jao taki k ki value utni hi rahe jitni h
            sum -= nums[i-k];
            //jo bhi maximum average aaye wo answer me store krlo 
            ans = max(ans , sum/(double)k);
        }
        return ans;
    }
};