class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxi = INT_MIN;
        int area = 0;
        while(i < j)
        {
            area = (j - i) * min(height[i], height[j]);
            maxi = max(maxi, area);

            if(height[i] < height[j])
                i++;
            else
                j--;

        }
        return maxi;
    }
};