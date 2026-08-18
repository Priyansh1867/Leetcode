class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        stack<int>st;

        //Loop ko circular bnane ke liye (2*n-1 to 0) times chalana pdega
        for(int i=2*n-1 ; i>=0 ; i--)
        {
            int curr = nums[i % n];

            //Maintain krte h monotonic decreasing stack
            while(!st.empty() && st.top() <= curr)
            {
                st.pop();
            }
            //first pass me hi answer me store kara lo n-1 time chalake
            if(i < n )
            {
                ans[i] = st.empty() ? -1 : st.top();
            }

            //push current element for subsequent elements to see
            st.push(curr);
        }
        return ans;
    }
};