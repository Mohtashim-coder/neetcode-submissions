class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // Using Dijkstra's Algorithm (Priority Queue)

        // Build adjacency list: {neighbor, time}
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto &edge : times)
        {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];

            graph[u].push_back({v, t});
        }

        // Distance array: min time to reach each node
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        // Min-heap: {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});

        while(!pq.empty())
        {
            auto[time, node] = pq.top();
            pq.pop();

            // skip if already found a better path
            if(time > dist[node])
            {
                continue;
            }

            // Explore neighbor
            for(auto [neighbor, travelTime] : graph[node])
            {
                int newTime = time + travelTime;
                if(newTime < dist[neighbor])
                {
                    dist[neighbor] = newTime;
                    pq.push({newTime, neighbor});
                }
            }
        }

        // Find maximum distance
        int maxTime = 0;
        for(int i=1; i<=n; i++)
        {
            if(dist[i] == INT_MAX)
            {
                return -1;
            }
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
