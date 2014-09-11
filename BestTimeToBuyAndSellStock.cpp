/**
 * @file BestTimeToBuyAndSellStock.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-29
 */

class Solution {
	public:
    int maxProfit(vector<int> &prices) {
	        if (prices.size() == 0){
			            return 0;
			        }

	        int maxPrice = prices[prices.size() - 1];
	        int ans = 0;

	        for (int i = prices.size() - 1; i >= 0; i --){
			            maxPrice = max(maxPrice,prices[i]);
			            ans = max(ans,maxPrice - prices[i]);
			        }

	        return ans;

	    }
};
