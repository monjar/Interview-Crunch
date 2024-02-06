
//link: https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/451/

class Solution {
public:
    
    
    int calculateLongestPalindromes(int i, int j,  string &s,  int **dp){
        dp[i][i] = 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        
        bool areEndsEqual = s[i] == s[j];
                
        if(j - i <= 2)
            dp[i][j] = areEndsEqual;
        else
            dp[i][j] = calculateLongestPalindromes(i+1, j-1, s, dp) && areEndsEqual;
        
        return dp[i][j];
        
    }
    string longestPalindrome(string s) {
        
        const int size = s.length();
       
        
        int **dp;
        dp = new int *[size];
        for(int i = 0; i <size; i++)
            dp[i] = new int[size];
       
        for(int i = 0; i <size; i++)
            for(int j = 0; j <size; j++)
                dp[i][j] = -1;
       
        
        for(int i  = 0; i < size; i++)
            for(int j  = i; j < size; j++)
                calculateLongestPalindromes(i, j, s, dp);
        
        int maxPalindromeStart = -1;
        int maxPalindromeSize = 0;
        for(int i  = 0; i < size; i++){
            for(int j  = i; j < size; j++){
                if(dp[i][j] == 1 && maxPalindromeSize < j - i + 1){
                    maxPalindromeStart = i;
                    
                    maxPalindromeSize = j - i + 1;
                }
            }
        }
        return s.substr(maxPalindromeStart, maxPalindromeSize);
    }
};