class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        //1. counting occurence or frequency of every element.
        for(int i=0 ; i<n ; i++)
        {
            int occurence = arr[i];
            mp[occurence]++;
            
        }
        //2. Checking frequencies are unique 
        unordered_set<int>uniqueCount;
        for(auto pair : mp)
        {
            int freq = pair.second;
            //Agar frequency count unique nhi h toh false return krdo
            if(uniqueCount.find(freq) != uniqueCount.end())
            {
                return false;
            }
            //jo bhi unique coun aaye use frequency me add or insert krte jao.
            uniqueCount.insert(freq);
            
        }
        return true;
        
    }
};