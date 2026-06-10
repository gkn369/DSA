class Solution {
public:
    int longestCycleLen = -1;
    void dfs(int cycleLen, int node, vector<int>& visited, vector<int>& currentPath, vector<int>& edges)
    {
        cycleLen++;
        visited[node] = 1;
        currentPath[node] = cycleLen;

        int nbr = edges[node];
        if(nbr != -1)
        {
            if(!visited[nbr])
            {
                dfs(cycleLen, nbr, visited, currentPath, edges);
            }
            else if(currentPath[nbr] != 0)
            {
                int currCycleLen = currentPath[node] - currentPath[nbr] + 1;
                longestCycleLen = max(longestCycleLen, currCycleLen);
            }
            
        }
        currentPath[node] = 0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> currentPath(n, 0);

        for(int i = 0; i < n; i++)
        {
            if(visited[i] != 1)
            {
                dfs(0, i, visited, currentPath, edges);
            }
        }

        return longestCycleLen;
    }
};