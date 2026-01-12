class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0, sum = 0;
        if(k < 0)
            return 0;
        while(j < n)
        {
            sum += (nums[j] % 2);

            while(sum > k)
            {
                sum -= (nums[i] % 2);
                i++;
            }
            count += j - i + 1; 
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return solve(nums, k) - solve(nums, k-1);
    }
};