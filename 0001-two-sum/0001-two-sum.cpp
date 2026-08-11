class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //map declare kr lege
        unordered_map<int,int>map;
        for(int i=0 ; i<nums.size() ; i++)
        {
            //remainder nikal lege 
            int remainder = target - nums[i];
            //remainder find kr lege ki pehle se map me present h ya nhi 
            if(map.find(remainder) != map.end())
            {
                //agar remainder nhi mila map me toh use j me store kro isme remainder ka index store ho rha h 
                int j = map[remainder];
                //return krdo {j,i} ko kyuki wo index bta rahe h 
                return {j , i};
            }
            //jo i hai wo map[nums[i]] me store krte jao and check krte jao upper wale loop se jab tak apna target mil nhi jata
            map[nums[i]] = i;
        }
        //for safe case empty string return krwa do taki agar target hua hi nhi toh empty return krdega.
        return {};
    }
};