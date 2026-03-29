class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int ones = -1, twos = -1, ans = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
                ones = i;
            else if(nums[i] == 2)
                twos = i;
            if(ones != -1 && twos != -1)
                ans = min(ans, abs(ones - twos));
        }
        return ans == INT_MAX ? -1 : ans;

    }
};