//link : https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/3085/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int size = nums.size();
        
        vector<vector<int>> dp(size+1,vector<int>(2, 0));

      
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for(int i = 1; i < size; i++){
            int disconnectedMaxSum = max(dp[i - 1][0], dp[i - 1][1]);
            int connectedMaxSum  = max(nums[i], dp[i - 1][1] + nums[i]);
            
            dp[i][0] = disconnectedMaxSum;
            dp[i][1] = connectedMaxSum;
        }
        
        
        return max(dp[size - 1][0], dp[size - 1][1]);
    }
};