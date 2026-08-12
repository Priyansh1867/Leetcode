class Solution {
public:
    double findpow(double x , int n)
    {
        //Base Case ,agar power 0 h toh power 1 return kr dege
        if(n == 0) return 1;
        //a me x ki power n/2 store kr lege
        double a = findpow(x,n/2);
        // agar power even h toh return a*a 
        if(n%2 == 0) return a*a;
        // agar power odd h toh return a*a*x;
        else return a*a*x;
    }
    double myPow(double x, int n) {
        //agar power 0 h toh power 1 return kr dege
        if(n == 0) return 1;
        //agar n>0 h toh power func ko call krege
        else if(n > 0) return findpow(x,n);
        else // if(n < 0)
        {
            //kyuki n<0 h toh power negative me h
            //TLE se bachne ke liye long long use krege aur usme power store kr lege 
            long long b = n;
            // b ko -1 se multiply kr dege taki wo positive ho
            b *= -1;
            //jo bhi power hogi wo 1/power hoegi
            return 1/findpow(x,b);
        }
    }
};