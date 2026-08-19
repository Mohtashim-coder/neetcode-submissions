class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Initialize distances
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        // Bellman-Ford: relax edges for k+1 iterations
        // (k stops = k+1 edges)
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;  // Copy current distances
            
            for (auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                
                if (dist[from] != INT_MAX) {
                    temp[to] = min(temp[to], dist[from] + price);
                }
            }
            
            dist = temp;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
