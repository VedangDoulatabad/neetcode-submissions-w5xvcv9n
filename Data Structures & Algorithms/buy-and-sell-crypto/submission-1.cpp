class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy = prices[0];
        int profit = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            bestbuy = min(bestbuy,prices[i]);
            profit = max(profit,prices[i] - bestbuy);
        }

        return profit;

    }
};
