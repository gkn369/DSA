class Solution {
  public:
    int solve(vector<int>& arr, int n, int currSum, int target, vector<vector<int>> &dp)
    {
        // if(currSum > target)
        //     return 0;
            
        if(n == 0)
            return currSum == target;
            
        if(dp[n][currSum] != -1)
            return dp[n][currSum];
        
        if(arr[n-1] + currSum <= target)
            return dp[n][currSum] = solve(arr, n-1, currSum + arr[n-1], target, dp) + solve(arr, n-1, currSum, target, dp);
        else
            return dp[n][currSum] = solve(arr, n-1, currSum, target, dp);
            
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int currSum = 0;
        
        vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));
        
        return solve(arr, n, currSum, target, dp);
    }
};