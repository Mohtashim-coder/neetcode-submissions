class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  // Stores indices, maintaining increasing order
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            // When i == n, process with height 0 (sentinel)
            int currentHeight = (i == n) ? 0 : heights[i];
            
            // While stack is not empty and current height is smaller
            // than height at stack top
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                // Calculate width
                int left = st.empty() ? -1 : st.top();
                int right = i;
                int width = right - left - 1;
                
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};