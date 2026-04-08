class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char,int> freqc, freqm;
        for(auto it : s)
        {
            freqc[it]++;
        }
        for(auto it : s)
        {
            if (freqc[it] == -1) 
                continue;
            char mirror;

            if(isdigit(it))
            {
                mirror = '9' - (it - '0');
            }
            else
                mirror = 'z' - (it - 'a');

                ans += abs(freqc[it] - freqc[mirror]);

                freqc[it] = -1;
                freqc[mirror] = -1;
        }

        return ans;
    }
};