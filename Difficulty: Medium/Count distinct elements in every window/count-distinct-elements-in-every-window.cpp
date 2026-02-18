class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        
        int i = 0, j = 0, n = arr.size(), count = 0;
        
        vector<int> ans;
        
        while(j < n)
        {
            mp[arr[j]]++;
            
            if(mp[arr[j]] == 1)
                count++;
                
            if(j - i + 1 == k)
            {
                ans.push_back(count);
                mp[arr[i]]--;
                if(mp[arr[i]] == 0)
                {
                    count--;
                    mp.erase(arr[i]);
                }
                i++;
            }
            j++;
        }
        
        return ans;
    }
};