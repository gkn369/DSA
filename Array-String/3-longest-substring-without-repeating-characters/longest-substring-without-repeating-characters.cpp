class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;
        int i = 0, j = 0;
        int maxi = 0;
        while(j < n)
        {
            while(st.find(s[j]) != st.end())
            {
                st.erase(s[i++]);
            }
            st.insert(s[j]);
            maxi = max(maxi,  j - i + 1);
            j++;
        }
        return maxi;
    }
};