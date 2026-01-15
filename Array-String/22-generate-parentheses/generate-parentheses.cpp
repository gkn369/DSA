class Solution {
public:
    void solve(int open, int close, string op, vector<string> &str)
    {
        if(open == 0 && close == 0)
        {
            str.push_back(op);
            return;
        }
        if(open != 0)
        {
            string op1 = op;
            op1.push_back('(');
            solve(open-1, close, op1, str);
        }
        if(open < close)
        {
            string op2 = op;
            op2.push_back(')');
            solve(open, close - 1, op2, str);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> str;
        int open = n, close = n;
        string op;
        solve(open, close, op, str);

        return str;
    }
};