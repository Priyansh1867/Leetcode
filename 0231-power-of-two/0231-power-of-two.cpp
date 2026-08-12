//By Recursion , Time complexity :- O(log n)
class Solution
{
    public:
    bool isPowerOfTwo(int n)
    {
        if(n==0) return false;
        if(n==1) return true;
        if(n%2 == 1) return false;

        return isPowerOfTwo(n/2);
    }
};

/*
//method 1 by while loop
class Solution
{
    public:
    bool isPowerOfTwo(int n)
    {
        if(n <= 0) return false;
        while(n % 2 == 0)
        {
            n /= 2;
        }
        return n==1;
    }
};

method 2

class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i=0 ; i<31 ; i++){
            int ans = pow(2,i);
            if (ans == n){
                return true;
            }
        }return false;
    }
};

//method 3

class Solution {
    public : 
    bool isPowerOfTwo(int n){
        int ans = 1;
        for(int i =0;i<31;i++){
            if (ans == n ){
                return true;
            }
            if(ans < INT_MAX/2){
            ans = ans * 2;
            }
        }return false;
    }
};
*/