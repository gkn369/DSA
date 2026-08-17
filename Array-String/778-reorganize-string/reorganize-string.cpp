class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto &[ch, freq] : mp)
        {
            pq.push({freq, ch});
        }
        string ans;
        while(pq.size() >= 2)
        {
            auto f1 = pq.top();
            pq.pop();
            auto f2 = pq.top();
            pq.pop();

            ans += f1.second; ans += f2.second;
            if(--f1.first > 0)
                pq.push({f1.first, f1.second});
            if(--f2.first > 0)
                pq.push({f2.first, f2.second});
        }

        while(!pq.empty())
        {
            auto e1 = pq.top();
            pq.pop();
            if(e1.first > 1)
                return "";
            ans += e1.second;
        }

        return ans;

    }
};