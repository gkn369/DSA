class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        int n = bulbs.size();
        map<int, int>mp;

        for(int i = 0; i < n; i++)
        {
            if(mp.find(bulbs[i]) == mp.end())
                mp[bulbs[i]]++;
            else
            {
                mp[bulbs[i]]--;
                mp.erase(bulbs[i]);
            }
        }

        for(auto it: mp)
        {
            if(it.second == 1)
                ans.push_back(it.first);
        }

        return ans;
    }
};