/**
 * @file BestTimeToBuyAndSellStock4.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
class Solution {
public:
//http://www.cnblogs.com/grandyang/p/4295761.html
    int totalProfit(vector<int> &prices){
        int profit = 0;
        for (int i = 1; i < prices.size(); i++){
            if(prices[i] - prices[i - 1] > 0){
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;

    }
    int maxProfit(int k, vector<int> &prices) {
        int result = 0;
        if (prices.size() == 0){
            return result;
        }
        if (k >= prices.size()){
            return totalProfit(prices);
        }
        int g[k + 1] = {0};
        int l[k + 1] = {0};
        for (int i = 0; i < prices.size() - 1; i++){
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; j --){
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
};
