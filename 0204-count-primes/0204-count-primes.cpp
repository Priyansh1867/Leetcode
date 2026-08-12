class Solution {
public:
    int countPrimes(int n) {
        // Base case: There are no prime numbers strictly less than 2
        if(n <= 2) return 0;
        // Create a boolean array where isPrime[i] indicates whether 'i' is prime.
        // Initially, assume all numbers up to n are prime.
        vector<bool>isPrime(n,true);
        // Explicitly set 0 and 1 as non-prime numbers
        isPrime[0] = isPrime[1] = false;

       // Iterate through potential prime factors up to sqrt(n)
        for(int i=2 ; i*i<n ; i++)
        {
            // If i is prime, mark all of its multiples as non-prime (composite)
            if(isPrime[i])
            {
                // Start marking multiples from i*i, as smaller multiples (e.g., 2*i, 3*i)
                // have already been marked by smaller prime factors.
                for(int j=i*i ; j<n ; j+=i)
                {
                    isPrime[j] = false;
                }
            }          
        }
        // Count all remaining numbers in the range [2, n-1] that are still marked as prime
        int count = 0;
        for(int i=2 ; i<n ; i++)
        {
            if(isPrime[i]) count++;
        }
        return count;
    }
};