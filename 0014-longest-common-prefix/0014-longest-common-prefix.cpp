class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Checking Horizontally and agar string match nhi hue toh empty return krdo
        if(strs.empty()) return {};
        // Start with the first string as the candidate prefix
        string prefix = strs[0];
        for(int i=0 ; i<strs.size() ; i++)
        {
            // Shorten prefix until strs[i] starts with it            
            while(strs[i].find(prefix) != 0)
            {
                prefix.pop_back(); // Remove last character
                if(strs.empty()) return {};
            }
        }
        return prefix;
    }
};