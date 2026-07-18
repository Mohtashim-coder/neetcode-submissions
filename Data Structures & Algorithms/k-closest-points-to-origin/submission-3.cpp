class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // 1. ARRAY: Input is array of points
        
        // Option A: SORTING (Array + Sorting + Math)
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            // 2. MATH: Calculate squared distance
            int distA = a[0]*a[0] + a[1]*a[1];
            int distB = b[0]*b[0] + b[1]*b[1];
            return distA < distB;
        });
        
        // Return first k points
        return vector<vector<int>>(points.begin(), points.begin() + k);
        
        /* === OR === */
        
        // Option B: MAX HEAP (Array + Heap + Math)
        auto compare = [](auto& a, auto& b) {
            int distA = a[0]*a[0] + a[1]*a[1];
            int distB = b[0]*b[0] + b[1]*b[1];
            return distA < distB;  // Max heap
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
        
        for (auto& point : points) {
            pq.push(point);
            if (pq.size() > k) pq.pop();
        }
        
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
        
        /* === OR === */
        
        // Option C: QUICKSELECT (Divide and Conquer + Quickselect)
        quickselect(points, 0, points.size() - 1, k);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    
private:
    // 3. DIVIDE AND CONQUER + QUICKSELECT
    int distance(const vector<int>& p) {
        return p[0]*p[0] + p[1]*p[1];  // MATH
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        int pivotDist = distance(points[right]);
        int i = left;
        
        for (int j = left; j < right; j++) {
            if (distance(points[j]) <= pivotDist) {
                swap(points[i], points[j]);
                i++;
            }
        }
        swap(points[i], points[right]);
        return i;
    }
    
    void quickselect(vector<vector<int>>& points, int left, int right, int k) {
        if (left >= right) return;
        
        int pivotIndex = partition(points, left, right);
        
        if (pivotIndex == k) return;
        else if (pivotIndex < k) {
            quickselect(points, pivotIndex + 1, right, k);
        } else {
            quickselect(points, left, pivotIndex - 1, k);
        }
    }
};