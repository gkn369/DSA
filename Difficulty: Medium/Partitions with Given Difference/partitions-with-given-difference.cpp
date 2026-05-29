class Solution {
  public:
    int solve(vector<int> &arr, int n, int currSum, int target, vector<vector<int>> &dp)
    {
        if(n == 0)
            return currSum == target;
            
        if(dp[n][currSum] != -1)
            return dp[n][currSum];
        
        if(arr[n-1] + currSum <= target)
            return dp[n][currSum] = solve(arr, n-1, currSum + arr[n-1], target, dp) + solve(arr, n-1, currSum, target, dp);
        else
            return dp[n][currSum] = solve(arr, n-1, currSum, target, dp);
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        
        if(diff > sum)
            return 0;

        if((sum + diff) % 2 != 0)
            return 0;
            
        int target = (sum + diff)/2;
        int currSum = 0;
        
        vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));
        
        return solve(arr, n, currSum, target, dp);
        
    }
};