class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Map to store the next greater element for each number in nums2: {element -> next_greater}
        unordered_map<int,int>mp;
        stack<int>st;

        // Traverse nums2 from right to left to find next greater elements
        for(int i=nums2.size()-1 ; i>=0 ; i--)
        {
            // Pop smaller or equal elements since they cannot be the next greater element
            while(!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            // If stack is empty, no greater element exists to the right (-1); otherwise, top of stack is the answer
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]); // Push current element to stack for elements on the left
        }
        // Build the result vector for nums1 using precomputed map values
        vector<int>ans;
        for(int num : nums1)
        {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};

/* To find next greater element 
class Solution {
public:
    vector<int>nextGreater(vector<int>&arr)
    {
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;

        for(int i=n-2 ; i>=0 ; i--)
        {
            while(!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3 = nextGreater(nums2);
        map<int,int>mp;
        for(int i=0 ; i<nums2.size() ; i++)
        {
            mp[nums2[i]] = nums3[i];
        }
        vector<int>ans;
        for(int i=0 ; i<nums1.size() ; i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};
*/