class Solution {
public:
    int MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n / 2;

        long long evenWays = power(5, even);
        long long oddWays = power(4, odd);

        return (evenWays*oddWays) % MOD;
    }
    long long power(long long base, long long pow)
    {
        long long ans = 1;
        while(pow > 0)
        {
            if(pow % 2 == 0)
            {
                base = (base * base) % MOD;
                pow = pow / 2;
            }
            else
            {
                ans = (ans * base) % MOD;
                pow -= 1;
            }
        }
        return ans;
    }
};