//Link:https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/3088/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        
        if(amount == 0)
            return 0;
        
        vector<int> filteredCoins;
        for(int coin: coins){
            if(coin > amount)
                continue;
            filteredCoins.push_back(coin);
            dp[coin] = 1;
        }
    
        
        for(int i = 0; i <= amount; i++){
            
            if(dp[i]!= -1)
                continue;
            int minCoins = -1;
            for(int coin: filteredCoins){
                int nextAmount = i - coin;
                if(nextAmount < 0 || dp[nextAmount]==-1)
                    continue;
                if(minCoins == -1)
                    minCoins =  dp[nextAmount] + 1;
            
                minCoins = min(minCoins, dp[nextAmount] + 1);
                
            }
            dp[i] = minCoins;
        }
        
    
           
        return dp[amount];
    }
};