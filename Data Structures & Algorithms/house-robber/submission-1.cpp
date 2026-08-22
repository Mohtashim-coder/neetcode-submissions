class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // dp[i] = max money from houses 0 to i
        vector<int> dp(n, 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            // Max of: rob current house + dp[i-2] OR skip current house
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        
        return dp[n-1];
    }
};