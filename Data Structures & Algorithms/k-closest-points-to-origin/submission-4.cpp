class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // 1. ARRAY: Input is array of points
        
        // Option A: SORTING (Array + Sorting + Math)
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int> & b) {
            // 2. MATH: Calculate squared distance
            int distA = a[0]*a[0] + a[1]*a[1];
            int distB = b[0]*b[0] + b[1]*b[1];
            return distA < distB;
        });

        vector<vector<int>> result;
        for(int i=0; i<k; i++)
        {
            result.push_back(points[i]);
        }
        return result;
        
    }
};