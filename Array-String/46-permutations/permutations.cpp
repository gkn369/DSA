//Backtracking
class Solution {
public:
    void solve(vector<int> &nums, int start, vector<vector<int>> &ans)
    {
        if(start == nums.size() - 1)
        {
            ans.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            solve(nums, start+1, ans);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        solve(nums, 0, ans);
        return ans;
    }
};

// //Recursion
// class Solution {
// public:
//     void solve(vector<int> nums, vector<int> op, vector<vector<int>> &ans)
//     {
//         if(nums.size() == 0)
//         {
//             ans.push_back(op);
//             return;
//         }
//         for(int i = 0; i < nums.size(); i++)
//         {
//             op.push_back(nums[i]);
//             vector<int>newip = nums;
//             newip.erase(newip.begin() + i);
//             solve(newip, op, ans);
//             op.pop_back();
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int n = nums.size();
//         vector<int> op;
//         solve(nums, op, ans);
//         return ans;
//     }
// };