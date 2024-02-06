//link:https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/3087/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        dp[0][1] = nums[0];
        dp[0][0] = nums[0];
     
        for(int i = 1; i < n; i++){
            dp[i][0] = min(min(dp[i - 1][0] * nums[i], nums[i]), dp[i - 1][1] * nums[i]);
            dp[i][1] = max(max(dp[i - 1][1] * nums[i], nums[i]),dp[i - 1][0] * nums[i]);
        }
        
        
     
        int maxNum = INT_MIN;
        for(int i = 0; i < n; i++){
            maxNum = max(maxNum, dp[i][1]);
        }
        
        return maxNum;
    }
};