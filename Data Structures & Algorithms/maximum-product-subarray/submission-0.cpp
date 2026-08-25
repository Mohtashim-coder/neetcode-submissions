class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize with first element
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < n; i++) {
            // If current number is negative, max and min swap
            if (nums[i] < 0) {
                swap(maxProduct, minProduct);
            }
            
            // Update max and min products ending at i
            maxProduct = max(nums[i], maxProduct * nums[i]);
            minProduct = min(nums[i], minProduct * nums[i]);
            
            // Update global result
            result = max(result, maxProduct);
        }
        
        return result;
    }
};