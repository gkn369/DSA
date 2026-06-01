class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& visited, int node)
    {
        visited[node] = 1;
        for(int i = 0; i < graph[node].size(); i++)
        {
            if(!visited[graph[node][i]])
            {
                dfs(graph, visited, graph[node][i]);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n);
        vector<vector<int>> graph(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0], b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(graph, visited, source);
        return visited[destination];
    }
};