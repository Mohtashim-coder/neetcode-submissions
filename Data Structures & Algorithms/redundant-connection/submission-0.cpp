class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);

        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(n+1, false);

            if(hasPath(graph, visited, u, v))
            {
                return edge;
            }

            // Add edge to graph
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }

private:
    bool hasPath(vector<vector<int>> &graph, vector<bool> &visited, int src, int dest)
    {
        if(src == dest)
        {
            return true;
        }

        visited[src] = true;

        for(int neighbor : graph[src])
        {
            if(!visited[neighbor])
            {
                if(hasPath(graph, visited, neighbor, dest))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
