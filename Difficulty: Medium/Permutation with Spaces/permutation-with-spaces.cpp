class Solution {
  public:
    void solve(string s, string op, vector<string> & ans)
    {
        if(s.size() == 0)
        {
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        op1.push_back(' ');
        op1.push_back(s[0]);
        op2.push_back(s[0]);
        s.erase(s.begin() + 0);
        solve(s, op1, ans);
        solve(s, op2, ans);
    }
    vector<string> permutation(string s) {
        // Code Here
        vector<string> ans;
        string op = "";
        op.push_back(s[0]);
        s.erase(s.begin() + 0);
        solve(s, op, ans);
        return ans;
    }
};