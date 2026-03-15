class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;

        vector<int> prefixGcd(n);

        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        } 
        sort(prefixGcd.begin(), prefixGcd.end());

        int start = 0, end = n - 1;
        long long sum = 0;
        while(start < end)
        {
            int a = prefixGcd[start++];
            int b = prefixGcd[end--];
            sum += gcd(a,b);
        }
        return sum;
    }
};