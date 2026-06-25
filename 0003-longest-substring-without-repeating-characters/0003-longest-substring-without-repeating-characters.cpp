class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool freq[256] = {false};

        //sliding window with frequency array (to check repeating characters)
        int i=0 , j=0;
        int n = s.size();
        int max_length = 0;
        while(j<n)
        {
            while (freq[s[j]] == true) //to check repating characters
            {
                freq[s[i]] = false;
                i++;
            }
            //if not exist in window and add them
            freq[s[j]] = true;
            int current_length = j-i+1;
            max_length = max(max_length , current_length);
            j++;
        }
        return max_length;
    }
};