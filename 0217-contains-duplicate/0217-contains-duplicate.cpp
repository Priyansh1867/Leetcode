class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>set;
        for(int element : nums)
        {
            if(set.find(element) != set.end()) return true; //Duplicate found
            set.insert(element);
        }
        return false;
    }
};