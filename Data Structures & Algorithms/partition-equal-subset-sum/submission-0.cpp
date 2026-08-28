class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;
        
        // If total sum is odd, cannot partition equally
        if (total % 2 != 0) return false;
        
        int target = total / 2;
        int n = nums.size();
        
        // dp[i] = true if we can achieve sum i
        vector<bool> dp(target + 1, false);
        dp[0] = true;  // We can always achieve sum 0
        
        for (int num : nums) {
            // Traverse backwards to avoid reusing same element
            for (int i = target; i >= num; i--) {
                if (dp[i - num]) {
                    dp[i] = true;
                }
            }
        }
        
        return dp[target];
    }
};