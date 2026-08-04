class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisities) {
        
        // build adjancency list
        vector<vector<int>> adj(numCourses);
        for(auto &prereq : prerequisities)
        {
            adj[prereq[1]].push_back(prereq[0]);
        }

        // 0 = Unvisited, 1 = Visiting, 2 = Visited
        vector<int> visited(numCourses, 0);
        for(int i=0; i<numCourses; i++)
        {
            if(visited[i] == 0)
            {
                if(hasCycle(adj, visited, i))
                {
                    return false;
                }
            }
        }
        return true;
    }

private: 
    bool hasCycle(vector<vector<int>> &adj, vector<int> &visited, int node)
    {
        // mark as currently visiting
        visited[node] = 1;

        // check all neighbours
        for(int neighbour : adj[node])
        {
            if(visited[neighbour] == 1)
            {
                return true;
            }

            if(visited[neighbour] == 0)
            {
                hasCycle(adj, visited, neighbour);
                return true;
            }
        }

        visited[node] = 2;
        return false;
    }
};
