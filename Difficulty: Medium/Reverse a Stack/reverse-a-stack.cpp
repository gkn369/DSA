class Solution {
  public:
    void insert(stack<int> &st, int val){
        if(st.size() == 0)
        {
            st.push(val);
            return;
        }
        int temp = st.top();
        st.pop();
        insert(st, val);
        st.push(temp);
    }
    void reverse(stack<int> &st)
    {
        if(st.size() == 1)
            return;
        
        int val = st.top();
        st.pop();
        reverse(st);
        insert(st, val);
    }
    void reverseStack(stack<int> &st) {
        // code here
        reverse(st);
    }
};