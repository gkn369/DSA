class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        int count_one = 0, count_zero = 0, valid_prefix = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
                count_zero += 1;
            else 
                count_one += 1;

            if(abs(count_one - count_zero) <= 1)
                valid_prefix++;
        }
        return valid_prefix;
    }
};