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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> current_path(n, 0);

        vector<vector<int>> adj(n);
        
        for(int i = 0; i < graph.size(); i++)
        {
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(i, adj, visited, current_path);
            }
        }

        vector<int> ans;
        for(int i=0; i<current_path.size(); i++)
        {
            if(current_path[i]==0)  
                ans.push_back(i);
        }
        return ans;
    }
};