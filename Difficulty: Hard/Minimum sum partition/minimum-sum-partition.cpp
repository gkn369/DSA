class Solution {
  public:
    bool subsetSum(vector<int>& nums, int n, int sum, vector<vector<int>>& dp)
    {
        if(n == 0)
            return 0;
        if(sum == 0)
            return 1;

        if(dp[n][sum] != -1)
            return dp[n][sum];
        
        if(nums[n-1] <= sum)
            dp[n][sum] = subsetSum(nums, n-1, sum - nums[n-1], dp) || subsetSum(nums, n-1, sum, dp);
        else
            dp[n][sum] = subsetSum(nums, n-1, sum, dp);

        return dp[n][sum];
    }
    // bool isSubsetSum(vector<int>& nums, int sum)
    // {
    //     int n = nums.size();

    //     vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    //     return subsetSum(nums, n, sum, dp);
    // }
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++)
            sum += nums[i];

        vector<vector<int>> dp(n + 1,
                               vector<int>(sum + 1, -1));

        int ans = INT_MAX;

        // checking all possible subset sums
        for(int j = 0; j <= sum; j++)
        {
            if(subsetSum(nums, n, j, dp))
            {
                ans = min(ans,
                          abs(sum - 2 * j));
            }
        }

        return ans;
        
    }
};
