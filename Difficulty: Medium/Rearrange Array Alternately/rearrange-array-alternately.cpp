class Solution {
  public:
    void rearrange(vector<int>& arr) {
        // Your code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int maxi = arr[n - 1] + 1;
        
        int j = n-1;
        for(int i = 0; i < n; i += 2)
        {
            arr[i] = arr[i] + (arr[j] % maxi)*maxi; 
            j--;
        }
        
        j = 0;
        
        for(int i = 1; i < n; i += 2)
        {
            arr[i] = arr[i] + (arr[j] % maxi) * maxi;
            j++;
        }
        
        for(int i = 0; i < n; i++)
        {
            arr[i] = arr[i]/maxi;
        }
    }
};