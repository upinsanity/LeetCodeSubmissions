#include<vector>
using namespace std;
/*
Leetcode #121
Given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Input: prices = [7,1,5,3,6,4]
Output: 5

Input: prices = [7,6,4,3,1]
Output: 0

Solution - 
At any time the max profit is the greatest difference between the stock with min price and the next stock with max price
*/
int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i]<minPrice)
                minPrice=prices[i];
            else if( prices[i]-minPrice>maxProfit)
                maxProfit=prices[i]-minPrice;
        }
        
        return maxProfit;
    }
