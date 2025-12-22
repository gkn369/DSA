class Solution {

  public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        // Your code goes here
        
        int n = a.size();
        int m = b.size();
        int suma = 0, sumb = 0;
        for(int i = 0; i < n; i++)
        {
            suma += a[i];
        }
        
        for(int i = 0; i < m; i++)
        {
            sumb += b[i];
        }
        
        int diff = abs(suma - sumb);
        
        if(diff == 0)
            return true;
        if(diff % 2 == 1)
            return false;
        
        if(suma > sumb)
        {
            set<int>st;
            
            for(int i : a)
            {
                st.insert(i);
            }
            
            int temp = diff/2;
            
            for(int i : b)
            {
                if(st.find(temp + i) != st.end())
                    return true;
            }
        }
        else
        {
            set<int>st;
            
            for(int i : b)
            {
                st.insert(i);
            }
            
            int temp = diff/2;
            
            for(int i : a)
            {
                if(st.find(temp + i) != st.end())
                    return true;
            }
        }
        return false;
    }
};