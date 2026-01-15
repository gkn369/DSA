class Solution {
public:
    void solve(int start, vector<vector<int>> &ans, vector<int> &res, int n, int k)
    {
        if(res.size() == k)
        {
            ans.push_back(res);
            return;
        }
        for(int i = start; i <= n; i++)
        {
            res.push_back(i);
            solve(i+1, ans, res, n, k);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(1, ans, res, n, k);
        return ans;
    }
};