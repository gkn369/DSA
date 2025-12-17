// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int low = 0, high = 0;
        int countLess = 0, n = arr.size();
        for(int i = 0; i < n; i++)
        {
            if(arr[i] <= k)
                countLess++;
        }
        int swap = 0;
        int ans = INT_MAX;
        while(high < n)
        {
            if(arr[high] > k)
                swap++;
            if(high - low >= countLess)
            {
                if(arr[low] > k)
                    swap--;
                low++;
            }
            if(high - low == (countLess - 1))
            {
                ans = min(ans, swap);
            }
            high++;
        }
        return ans;
    }
};
