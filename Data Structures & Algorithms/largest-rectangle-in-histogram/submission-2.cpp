class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  // Stores indices with increasing heights
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            // Use 0 as sentinel at the end to pop all remaining
            int currentHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && heights[st.top()] > currentHeight) {
                int height = heights[st.top()];
                st.pop();
                
                // Width: from after previous smaller to before current smaller
                int width = st.empty() ? i : i - st.top() - 1;
                
                maxArea = max(maxArea, height * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};