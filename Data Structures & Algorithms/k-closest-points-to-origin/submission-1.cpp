class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap: stores the k closest points so far
        // The largest distance stays at the top
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            int distA = a[0]*a[0] + a[1]*a[1];
            int distB = b[0]*b[0] + b[1]*b[1];
            return distA < distB;  // Max heap
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
        
        for (const auto& point : points) {
            pq.push(point);
            if (pq.size() > k) {
                pq.pop();  // Remove the farthest point
            }
        }
        
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
    }
};