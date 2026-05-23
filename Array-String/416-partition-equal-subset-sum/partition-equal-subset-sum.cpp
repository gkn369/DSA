class Solution {
public:
    bool subsetSum(vector<int>& nums, int target, int n)
    {
        vector<vector<bool>>dp(n+1, vector<bool>(target+1, false));

        for(int i = 0; i < n+1; i++)
        {
            for(int j = 0; j < target + 1; j++)
            {
                if(j == 0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = false;
                else if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int target = sum / 2;

        
        if(sum % 2 != 0)
            return false;
        else
        {
            return subsetSum(nums, target, n);
        }
    }
};