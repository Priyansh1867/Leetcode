class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX;
        int buy2 = INT_MAX;
        int profit1 = 0;
        int profit2 = 0;

        for(int price : prices)
        {
            //Transaction 1
            buy1 = min(buy1 , price);
            profit1 = max(profit1 ,price - buy1);

            //Transaction 2 
            // We reinvest profit1 into buy2, which lowers our effective cost
            buy2 = min(buy2 , price - profit1);
            profit2 = max(profit2 ,price - buy2);
        }
        return profit2;
    }
};