class Solution {
  public:
    int TotalPairs(vector<int> nums, int k) {
        // Code here
        int n = nums.size();
        
        map<int, int>mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        int ans = 0;
        if(k == 0)
        {
            for(auto it : mp)
            {
                if(it.second > 1)
                    ans++;
            }
        }
        else{
            for(auto it : mp)
            {
                if(mp.find(it.first + k) != mp.end())
                    ans++;
            }
        }
        
        return ans;
    }
};