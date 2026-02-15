class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        map<int, int> freq;
        map<int, int> freqCount;

        for(auto it : nums)
        {
            freq[it]++;
        }

        for(auto it : freq)
        {
            freqCount[it.second]++;
        }

        for(auto it : nums)
        {
            if(freqCount[freq[it]] == 1)
                return it;
        }

        return -1;
    }
};