class Solution {
public:
    vector<int> findNGE(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return ans;

    }

    vector<int> findPGE(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> findNSE(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return ans;

    }
    vector<int> findPSE(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return ans;

    }
    long long subMax(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> PGE = findPGE(arr);
        vector<int> NGE = findNGE(arr);

        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            int left = i - PGE[i];
            int right = NGE[i] - i;

            long long freq = left * right * 1LL;

            long long val = arr[i] * freq * 1LL;

            sum += val;
        }
        return sum;
    }

    long long subMin(vector<int> & arr)
    {
        int n = arr.size();
        vector<int> PSE = findPSE(arr);
        vector<int> NSE = findNSE(arr);

        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            int left = i - PSE[i];
            int right = NSE[i] - i;

            long long freq = left * right * 1LL;

            long long val = arr[i] * freq * 1LL;

            sum += val;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subMax(nums) - subMin(nums);
    }
};