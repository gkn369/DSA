class Solution {
  public:
    int maxProfit(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp)
    {
        if(n == 0 || W == 0)
            return 0;
        if(dp[n][W] != -1)
            return dp[n][W];
            
        if(wt[n - 1] <= W)
            return dp[n][W] = max(val[n-1] + maxProfit(W - wt[n-1], val, wt, n-1, dp), maxProfit(W, val, wt, n-1, dp));
        else if(wt[n - 1] > W)
            return dp[n][W] = maxProfit(W, val, wt, n-1, dp);
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        
        return maxProfit(W, val, wt, n, dp);
    }
};


















