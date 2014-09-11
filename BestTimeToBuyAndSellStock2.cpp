/**
 * @file BestTimeToBuyAndSellStock2.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-30
 */
class Solution {
	public:
    int maxProfit(vector<int> &prices) {
	        if (prices.size() == 0){
			            return 0;
			        }

	        int result = 0;

	        for (int i = 1; i < prices.size(); i ++){
			            if (prices[i] > prices[i - 1]){
						                result += (prices[i] - prices[i - 1]);
						            }
			        }

	        return result;
	    }
};
