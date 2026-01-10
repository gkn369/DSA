class Solution {
public:
    void solve(string s, string op, set<string> &res)
    {
        if(s.size() == 0)
        {
            res.insert(op);
            return;
        }

        string op1 = op;
        string op2 = op;
        
        if(isdigit(s[0]))
        {
            op1.push_back(s[0]);
        }
        else
        {
            op1.push_back(tolower(s[0]));
        }
        if(isdigit(s[0]))
        {
            op2.push_back(s[0]);
        }
        else
        {
            op2.push_back(toupper(s[0]));
        }
        s.erase(s.begin() + 0);
        solve(s, op1, res);
        solve(s, op2, res);
    }
    vector<string> letterCasePermutation(string s) {
        set<string>res;
        vector<string>ans;
        string op = "";
        solve(s, op, res);
        for(auto it : res)
        {
            ans.push_back(it);
        }
        return ans;
    }
};