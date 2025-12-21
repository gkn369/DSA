class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m)
            return false;
        unordered_map<char, int> s1map;
        unordered_map<char, int> s2map;
        for(int i = 0; i < n; i++)
        {
            s1map[s1[i]]++;
            s2map[s2[i]]++;
        }
        if(s1map == s2map)
            return true;
        int left = 0;
        int right = n;

        while(right < m)
        {
            s2map[s2[right]]++;
            s2map[s2[left]]--;
            if(s2map[s2[left]] == 0)
            {
                s2map.erase(s2[left]);
            }

            left++;
            right++;

            if(s1map == s2map)
                return true;
        }
        return false;
    }
};