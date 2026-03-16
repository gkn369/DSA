class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        long long start = 1000;
        int commas = 1;
        long long ans = 0;
        while(start <= n)
        {
            long long end = 1000 * start - 1;
            long long count = min(n, end) - start + 1;
            ans += count * commas;
            start *= 1000;
            commas++;
        }
        return ans;
    }
};