class Solution {
public:
    int jump(vector<int>& nums) {
        int ind = 0;
        int cnt = 0;
        int currentEnd = 0;
        int n = nums.size();
        for(int i = 0; i < n-1; i++)
        {
            ind = max(ind, i + nums[i]);

            if(i == currentEnd)
            {
                cnt++;
                currentEnd = ind;
            }
        }
        return cnt;
    }
};