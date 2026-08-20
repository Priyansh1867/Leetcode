class Solution {
public:
    int recursion(int n , vector<int>&dp)
    {
        //Base Case
        if(n == 0 || n == 1) return n;
        //check krege agar value update ho gyi means calculate ho gyi h ek baar toh return kr dege
        if(dp[n] != -1)
        {
            return dp[n];
        }
        // dp[n] = recursion(n-1 , dp) + recursion(n-2 , dp); ye bhi use kr skte h
        dp[n] = fib(n-1) + fib(n-2);
        return dp[n];
    }
    int fib(int n) {
        // ek dp vector bna lege jiska size n-1 rkhege aur sbme pehle hi -1 rkh dege.
        vector<int>dp(n+1 , -1); 
        return recursion(n , dp); 
    }
};