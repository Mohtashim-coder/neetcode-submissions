class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(points, 0, points.size() - 1, k);
        
        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(points[i]);
        }
        return result;
    }
    
private:
    void quickSelect(vector<vector<int>>& points, int left, int right, int k) {
        if (left >= right) return;
        
        int pivotIndex = partition(points, left, right);
        
        if (pivotIndex == k) return;
        else if (pivotIndex < k) {
            quickSelect(points, pivotIndex + 1, right, k);
        } else {
            quickSelect(points, left, pivotIndex - 1, k);
        }
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        // Choose rightmost as pivot
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
    
    int distance(const vector<int>& point) {
        return point[0]*point[0] + point[1]*point[1];
    }
};