class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string str = "";
        stack<string>st;
        string ans;
        int i = 0;
        while(i < n)
        {

            while(i < n && s[i] != ' ')
            {
                str += s[i];
                i++;
            }
            if(str != "")
                st.push(str);
            str = "";
            i++;
        }
        while(!st.empty() && st.size() > 1)
        {
            ans += st.top() + " ";
            st.pop();
        }

        ans += st.top();
        st.pop();
        return ans;
    }
};