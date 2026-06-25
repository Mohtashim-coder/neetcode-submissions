class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int left = 0;
        int right = heights.size() - 1;
        int maxWater = 0;

        while(left < right)
        {
            int width = right - left;
            int currHeight = min(heights[left], heights[right]);
            int area = width * currHeight;

            maxWater = max(maxWater, area);

            if(heights[left] < heights[right])
            {
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};
