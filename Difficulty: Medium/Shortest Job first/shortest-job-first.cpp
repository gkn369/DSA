// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(), bt.end());
        
        int n = bt.size();
        long long t = 0, wt = 0;
        for(int i = 0 ; i< n; i++)
        {
            wt += t;
            
            t += bt[i];
        }
        return wt/n;
    }
};