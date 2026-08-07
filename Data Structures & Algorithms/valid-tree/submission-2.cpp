class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n-1)
        {
            return false;
        }

        // create an adjecent list
        vector<vector<int>> adj(n);
        for(auto &edge : edges)
        {
            adj[edge[0]].push_back(edge(1));
            adj[edge[1]].push_back(edge(0));
        }

        vector<bool> visited(n, false);

        // DFS from node 0
        if(hasCycle(adj, visited, 0, -1))
        {
            return false;
        }

        // Check if all nodes were visited (connected)
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        return true;
    }

private:
    bool hasCycle(vector<vector<int>> &adj, vector<bool> &visited, int node, int parent)
    {
        visited[node] = true;
        for(int neighbor : adj[node])
        {
            if(neighbor == parent)
            {
                continue;
            }

            if(visited[neighbor])
            {
                return true; // found a cycle
            }

            if(hasCycle(adj, visited, neighbor, node))
            {
                return true;
            }
        }
        return false;
    }
};
