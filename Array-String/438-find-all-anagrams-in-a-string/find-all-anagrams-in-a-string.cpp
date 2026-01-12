class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();

        vector<int> s_freq(26,0);
        vector<int> p_freq(26,0);
        vector<int> ans;
        for(int i = 0; i < p_size; i++)
        {
            p_freq[p[i] - 'a']++;
        }
        int low = 0, high = 0;

        while(high < s_size)
        {
            s_freq[s[high] - 'a']++;

            while(high - low + 1 > p_size)
            {
                s_freq[s[low] - 'a']--;
                low++;
            }
            if(s_freq == p_freq)
                ans.push_back(low);

            high++;
        }
        return ans;
    }
};