class Solution {
public:
    bool isPowerOfThree(int n) {
        //agar n<=0 ho th negative ka cube nhi nikalna , return false
        if(n <= 0) return false;
        //check for cube, agar 3 se divisible h toh under jao
        while(n % 3 == 0)
        {
            //n ko 3 se divide krke remainder lao and ye chalate jao jab tak pura divisible nhi ho jaata
            n /= 3;
        }
        //agar sb sahi chala aur n==1 aa gya toh return true krdo
        return n == 1;
    }
};