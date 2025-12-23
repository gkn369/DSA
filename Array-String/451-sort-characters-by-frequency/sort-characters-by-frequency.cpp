class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(char ch : s)
        {
            mp[ch]++;
        }

        priority_queue<pair<int,char>> pq;
        string ans;
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }

        while(!pq.empty())
        {
            int n = pq.top().first;
            while(n--)
            {
                ans += pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};