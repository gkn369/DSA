class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;

        for(int i = 0; i < n; i++)
        {
            if(asteroids[i] > 0)
                st.push(asteroids[i]);
            else
            {
                bool destroyed = false;
                while(!st.empty() && st.top() > 0)
                {
                    if(st.top() < abs(asteroids[i]))
                    {
                        st.pop();
                        continue;
                    }
                    else if(st.top() == abs(asteroids[i]))
                    {
                        st.pop();
                        destroyed = true;
                        break;
                    }
                    else
                    {
                        destroyed = true;
                        break;
                    }
                }
                if(!destroyed)
                    st.push(asteroids[i]);
            }
        }
        vector<int> ans(st.size());
        for(int i = ans.size() - 1; i >= 0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};