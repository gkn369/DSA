class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int> mp;

        int n = nums.size();

        for(int it : nums)
        {
            mp[it]++;
        }

        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 0 && mp[nums[i]] < 2)
                return nums[i];
        }

        return -1;
    }
};