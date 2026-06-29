/*
Method 1 - time limit exceed
class Solution {
private :
bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2 ; i<n ; i++){
        if(n%i == 0){
            return false;
        }

    }
          return true;
}
public:
    int countPrimes(int n) {
        int count = 0;

        for(int i = 2; i<n ; i++){
            if(isPrime(i)){
                count++;
            }
           
        }
         return count;
    }
};
*/
//Method 2 - it also showing time limit exceeded.
class Solution{
    public:
    int countPrimes(int n){
        if(n <= 2) return 0;
       
        vector<bool>prime(n,true);
        prime[0] = prime[1] = false;

        for(int i=2 ; 2*i<n ; i++){
            if (prime[i])
            {
                for(int j=2*i ; j<n ; j+=i)
                {
                prime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i=2 ; i<n ; i++)
        {
            if(prime[i])
            {
                count++;
            }
        }
        return count;
    }
};