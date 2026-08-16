class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Edge list: {weight, u, v}
        vector<vector<int>> edges;
        
        // Calculate all pair distances
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = manhattan(points[i], points[j]);
                edges.push_back({dist, i, j});
            }
        }
        
        // Sort edges by weight (ascending)
        sort(edges.begin(), edges.end());
        
        // Union-Find
        UnionFind uf(n);
        int totalCost = 0;
        int edgesUsed = 0;
        
        // Process edges in order
        for (auto& edge : edges) {
            int weight = edge[0];
            int u = edge[1];
            int v = edge[2];
            
            if (uf.unionNodes(u, v)) {
                totalCost += weight;
                edgesUsed++;
                if (edgesUsed == n - 1) break;
            }
        }
        
        return totalCost;
    }
    
private:
    int manhattan(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    
    class UnionFind {
    private:
        vector<int> parent;
        vector<int> rank;
        
    public:
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        bool unionNodes(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            
            if (rootX == rootY) return false;
            
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
            
            return true;
        }
    };
};