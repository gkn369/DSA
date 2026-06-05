class Solution {
  public:
    vector<vector<int>> coordinates = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
    
    int helper(int src_x, int src_y, int target_x, int target_y, int n)
    {
        vector<vector<int>> visited(n, vector<int>(n));
        queue<pair<int, int>> q;
        
        q.push({src_x, src_y});
        
        visited[src_x][src_y] = 1;
        
        int steps = 0;
        
        while(!q.empty())
        {
            int qsize = q.size();
            while(qsize > 0)
            {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                if(x == target_x && y == target_y)
                {
                    return steps;
                }
                for(int k = 0; k < coordinates.size(); k++)
                {
                    int new_x = x + coordinates[k][0];
                    int new_y = y + coordinates[k][1];
                    
                    if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < n && visited[new_x][new_y] == 0)
                    {
                        visited[new_x][new_y] = 1;
                        q.push({new_x, new_y});
                    }
                }
                
                qsize--;
            }
            steps++;
        }
        return -1;
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        int src_x = n - knightPos[1], src_y = knightPos[0] - 1;
        int target_x = n - targetPos[1], target_y = targetPos[0] - 1;
        
        return helper(src_x, src_y, target_x, target_y, n);
    }
};