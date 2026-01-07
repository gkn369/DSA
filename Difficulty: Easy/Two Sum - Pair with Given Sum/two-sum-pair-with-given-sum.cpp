class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(target - arr[i]) != mp.end())
                return true;
            mp[arr[i]]++;
        }
        return false;
    }
};