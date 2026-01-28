class Solution {
public:
    int largestArea(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        int maxA = 0;

        for(int i = 0; i <= n; i++)
        {
            int h = (i == n) ? 0 : arr[i];
            while(!st.empty() && h < arr[st.top()])
            {
                int height = arr[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxA = max(maxA, height*width);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return 0;
        int m = matrix[0].size();

        vector<int> hist(m,0);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                    hist[j] += 1;
                else
                    hist[j] = 0;
            }
            ans = max(ans, largestArea(hist));
        }
        return ans;
    }
};