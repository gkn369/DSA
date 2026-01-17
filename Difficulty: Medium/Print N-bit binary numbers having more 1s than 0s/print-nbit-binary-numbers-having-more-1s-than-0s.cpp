// User function template for C++
class Solution {
  public:
    void solve(int one, int zero, string op, int n, vector<string> &ans)
    {
        if(n == 0)
        {
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        op1.push_back('1');
        solve(one+1, zero, op1, n-1, ans);
        
        if(one > zero)
        {
            string op2 = op;
            op2.push_back('0');
            solve(one, zero+1, op2, n-1, ans);
        }
    }
    vector<string> NBitBinary(int n) {
        // Your code goes here
        int one = 0, zero = 0;
        vector<string>ans;
        string op;
        solve(one, zero, op, n, ans);
        return ans;
    }
};