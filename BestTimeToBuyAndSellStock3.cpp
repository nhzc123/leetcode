/**
 * @file BestTimeToBuyAndSellStock3.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-30
 */
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &prices) {
        if (prices.size() == 0 || prices.size() == 1){
            return 0;
        }

        int result = 0;
        vector<int> head(prices.size() );
        vector<int> tail(prices.size() );
        int minPrice = INT_MAX;
        int profit = 0;
        int maxPrice = INT_MIN;

        //先从前面往后扫，找出i个位置的最大收益
        for (int i = 0; i < prices.size(); i ++){
            minPrice = min(minPrice,prices[i]);
            profit = max(prices[i] - minPrice,profit);
            head[i] = profit;
        }
        profit = 0;

        //从后面往前面扫，找出i个位置的最大收益(反过来搜索则是最大亏损)
        for (int i = prices.size() - 1; i >= 0; i --){
            maxPrice = max(maxPrice,prices[i]);
            profit = max(maxPrice - prices[i],profit);
            tail[i] = profit;
        }
        profit = 0;
        //然后合并两个数组，得到在i天交易前能得到的最大收益 + i天后交易得到的最大收益
        for (int i = 0; i < prices.size(); i ++){
            profit = max(profit, head[i] + tail[i]);
        }

        return profit;


    }

int maxProfit1(vector<int> &prices) {
        int minPrice=INT_MAX, maxPrice=INT_MIN, maxProfit=0, curProfit, n=prices.size();
        if(n)
        {
            vector<int> maxProfitBeforeDay(n), maxProfitAfterDay(n);
            for(int i=0; i<n; i++)//1st scan, find maxProfit during 0th to ith day.
            {
                if(prices[i]<minPrice)minPrice=prices[i];
                curProfit=prices[i]-minPrice;
                if(curProfit>maxProfit)maxProfit=curProfit;
                maxProfitBeforeDay[i]=maxProfit;
            }
            maxProfit=0;
            for(int i=n-1; i>=0; i--)//2nd scan, find maxProfit during ith to (n-1)th day.
            {
                if(prices[i]>maxPrice)maxPrice=prices[i];
                curProfit=maxPrice-prices[i];
                if(curProfit>maxProfit)maxProfit=curProfit;
                maxProfitAfterDay[i]=maxProfit;
            }
            for(int i=0; i<n; i++)//3rd scan, find maxProfit in total.
            {
                curProfit=maxProfitBeforeDay[i]+maxProfitAfterDay[i];
                if(curProfit>maxProfit)maxProfit=curProfit;
            }
        }
        return maxProfit;
    }

int main(){
	vector<int> tem;
	tem.push_back(3);
	tem.push_back(2);
	tem.push_back(6);
	tem.push_back(5);
	tem.push_back(0);
	tem.push_back(3);
	tem.push_back(10);

	cout<<maxProfit(tem)<<endl;
	cout<<maxProfit1(tem)<<endl;
	return 0;
}
