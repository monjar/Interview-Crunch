//Link: https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/3086/

class Solution {
public:
    
    
    
    
    int maxProfit(vector<int>& prices) {
        vector<pair<int, int>> minimumPriceBeforeDay(prices.size());
        vector<pair<int, int>> maximumPriceAfterDay(prices.size());
        

        
        int minimumPrice = INT_MAX;
        int mimimumPriceDay = -1;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minimumPrice){
                minimumPrice = prices[i];
                mimimumPriceDay = i;
            }
            
            pair<int, int> minDayPricePair(mimimumPriceDay, minimumPrice);
            minimumPriceBeforeDay[i] = minDayPricePair;
        }
        
        
        
        int maximumPrice = INT_MIN;
        int maximumPriceDay = -1;
        
        for(int i = prices.size() - 1; i >=0 ; i--){
            if(prices[i] > maximumPrice){
                maximumPrice = prices[i];
                maximumPriceDay = i;
            }
            
            
            pair<int, int> maxDayPricePair(maximumPriceDay, maximumPrice);
            maximumPriceAfterDay[ i] = maxDayPricePair;
        }
        
        
      
         int maxProfit = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(maximumPriceAfterDay[i].first <= minimumPriceBeforeDay[i].first)
                continue;
            int currentProfit = maximumPriceAfterDay[i].second - minimumPriceBeforeDay[i].second;
            if(currentProfit > maxProfit)
                maxProfit = currentProfit;
        }
        
        
        return maxProfit;

    }
};