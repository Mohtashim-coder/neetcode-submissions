class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // one pass track minimum (optimal)
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int price : prices)
        {
            if(price < minPrice)
            {
                minPrice = price;
            }
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;

    }
};
