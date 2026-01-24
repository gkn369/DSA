class Solution {
public:
    void solve(vector<int> candidates, vector<int> &nums, vector<vector<int>> &ans, int currSum, int currInd, int target)
    {
        if(currSum > target)
            return;
        if(currSum == target)
        {
            ans.push_back(nums);
            return;
        }
        int n = candidates.size();
        for(int i = currInd; i < n; i++)
        {
            currSum += candidates[i];
            nums.push_back(candidates[i]);
            solve(candidates, nums, ans, currSum, i, target);
            nums.pop_back();
            currSum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nums;
        vector<vector<int>> ans;
        solve(candidates, nums, ans, 0, 0, target);
        return ans;
    }
};