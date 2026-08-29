class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        int n = s.size();
        set<string> st(dictionary.begin(), dictionary.end());
        string ans, str;
        bool find = false;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != ' '){
                str += s[i];
                if(!find && st.find(str) != st.end()){
                    ans += str;
                    find = true;
                }
            }
            else{
                if(!find)
                    ans += str;
                ans += ' ';
                str = "";
                find = false;
            }

        }
        if(!find)
            ans += str;

        return ans;
    }
};