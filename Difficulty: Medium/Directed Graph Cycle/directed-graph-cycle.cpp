class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& current_path)
    {
        visited[node] = 1;
        current_path[node] = 1;
        
        for(int nbr : adj[node])
        {
            if(!visited[nbr])
            {
                if(dfs(nbr, adj, visited, current_path))
                    return true;
            }
            else
            {
                if(current_path[nbr] == 1)
                    return true;
            }
            
        }
        current_path[node] = 0;
        return false;
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> visited(V, 0), current_path(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, adj, visited, current_path))
                    return true;
            }
        }
        return false;
    }
};