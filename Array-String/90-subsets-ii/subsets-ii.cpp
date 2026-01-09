class Solution {
public:
    void solve(vector<int> nums, vector<int> op, map<vector<int>, int>& mp)
    {
        if(nums.size() == 0)
        {
            mp[op]++;
            return;
        }
        vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(nums[0]);
        nums.erase(nums.begin() + 0);
        solve(nums, op1, mp);
        solve(nums, op2, mp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans;
        vector<int>op;
        map<vector<int>, int>mp;
        solve(nums,op, mp);
        for(auto it : mp)
        {
            ans.push_back(it.first);
        }
        return ans;
    }
};