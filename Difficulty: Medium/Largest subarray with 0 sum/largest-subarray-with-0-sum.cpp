class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        unordered_map<int, int> mp;
        
        mp[0] = -1;
        
        int count = 0;
        int maxCount = 0;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(mp.find(sum) != mp.end())
                count = i - mp[sum];
            else
                mp[sum] = i;
                
            if(count > maxCount)
                maxCount = count;
        }
        return maxCount;
    }
};