//Tabulation Approach :- Down to Top Approach
class Solution {
public:
    int fib(int n) {
        //Base Case
        if(n == 0 || n == 1) return n;
        //vector bna lege dp name ka and size n+1 rkh dege
        vector<int>dp(n+1);
        dp[0] = 0; // 1st value 0
        dp[1] = 1; // 2nd value 1

        //loop 2 se n tak chalayege 
        for(int i=2 ; i<=n ; i++)
        {
            // starting se values calculate krke dp[i] me store krte jao
            dp[i] = dp[i-1] + dp[i-2];
        }
        // last me jo value  aayi dp[n] ki wo return krdo
        return dp[n];
    }
};