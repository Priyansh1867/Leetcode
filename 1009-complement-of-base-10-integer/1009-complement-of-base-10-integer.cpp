class Solution {
public:
    int bitwiseComplement(int n) {
        int m = n ;
        int p = 0;

        if(n == 0)return 1;

        while(m != 0)
        {
            p = (p << 1) | 1;
            m = m >> 1;
        }
        int ans = (~n) & p;
        return ans;
    }
};