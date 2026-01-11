class Solution {
public:
    void permute(vector<int> nums, vector<int> &op, vector<vector<int>> & ans)
    {
        if(nums.size() == 0)
        {
            ans.push_back(op);
            return;
        }
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++)
        {
            if(st.find(nums[i]) == st.end())
            {
                st.insert(nums[i]);
                op.push_back(nums[i]);
                vector<int> newip = nums;
                newip.erase(newip.begin() + i);

                permute(newip, op, ans);

                op.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;

        permute(nums, op, ans);
        return ans;
    }
};