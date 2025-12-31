class Solution {
  public:
    void insert(stack<int> &st, int temp)
    {
        if(st.size() == 0 || st.top() <= temp)
        {
            st.push(temp);
            return;
        }
        int val = st.top();
        st.pop();
        insert(st, temp);
        st.push(val);
    }
    void sort(stack<int> &st)
    {
        if(st.size() == 1)
            return;
            
        int temp = st.top();
        st.pop();
        sort(st);
        insert(st, temp);
    }
    void sortStack(stack<int> &st) {
        // code here
        sort(st);
        return;
    }
};
