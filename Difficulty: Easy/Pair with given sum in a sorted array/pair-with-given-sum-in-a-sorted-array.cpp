
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n = arr.size();
        int count = 0;

        unordered_map<int, int>mp;
        
        for(int i = 0; i < n; i++)
        {
            if(mp.find(target - arr[i]) != mp.end())
                count += mp[target - arr[i]]; 
            mp[arr[i]]++;
        }
        
        return count;
        
    }
};