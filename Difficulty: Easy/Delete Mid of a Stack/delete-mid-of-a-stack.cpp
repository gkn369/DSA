class Solution {
  public:
    // Function to delete middle element of a stack.
    void del(stack<int>& s, int k)
    {
        if(s.size() == 0)
            return;
        
        int count = 0;
        if(k == 1)
        {   s.pop();
            return;
        }
        int val = s.top();
        s.pop();
        del(s, k-1);
        s.push(val);
    }
    void deleteMid(stack<int>& s) {
        // code here..
        int k = s.size()/2 + 1;
        del(s,k);
        return;
    }
};