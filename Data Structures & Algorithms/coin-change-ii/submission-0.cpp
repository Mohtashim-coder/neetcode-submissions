class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[i][j] = number of ways to make amount j using first i coins
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        
        // Base case: 1 way to make amount 0 (using no coins)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                // Exclude current coin
                dp[i][j] = dp[i-1][j];
                
                // Include current coin (unlimited supply)
                if (j >= coins[i-1]) {
                    dp[i][j] += dp[i][j - coins[i-1]];
                }
            }
        }
        
        return dp[n][amount];
    }
};