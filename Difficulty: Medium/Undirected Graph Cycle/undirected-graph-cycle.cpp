class Solution {
  public:
    bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adj)
    {
        visited[node] = 1;
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                int ans = dfs(it, node, visited, adj);
                if(ans)
                    return true;
            }
            else if(visited[it] == 1 && it != parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> visited(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, -1, visited, adj))
                    return true;
            }
        }
        return false;
    }
};