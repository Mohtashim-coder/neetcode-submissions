class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        // Three states:
        // hold[i] = max profit on day i when holding a stock
        // sold[i] = max profit on day i after selling (cooldown next day)
        // cooldown[i] = max profit on day i in cooldown period
        
        vector<int> hold(n, 0);
        vector<int> sold(n, 0);
        vector<int> cooldown(n, 0);
        
        // Base cases
        hold[0] = -prices[0];
        sold[0] = 0;
        cooldown[0] = 0;
        
        for (int i = 1; i < n; i++) {
            // Hold: either continue holding, or buy from cooldown
            hold[i] = max(hold[i-1], cooldown[i-1] - prices[i]);
            
            // Sold: must sell from hold state
            sold[i] = hold[i-1] + prices[i];
            
            // Cooldown: max of previous sold or cooldown
            cooldown[i] = max(cooldown[i-1], sold[i-1]);
        }
        
        // Final answer: max of sold and cooldown (cannot end with hold)
        return max(sold[n-1], cooldown[n-1]);
    }
};
