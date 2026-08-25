class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = minimum coins to make amount i
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;  // 0 coins needed to make 0
        
        // For each amount from 1 to amount
        for (int i = 1; i <= amount; i++) {
            // Try each coin
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
