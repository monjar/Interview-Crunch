//link : https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3072/


class Solution {
public:
    
    struct Cell{
        int i;
        int j;
    };
    
    vector<Cell> getIncreasingNeighbors(vector<vector<int>>& matrix, int i, int j){
        vector<Cell> neighbors;
        int currentCellValue = matrix[i][j];
        if(i > 0 && matrix[i-1][j] > currentCellValue){
            Cell c = {i-1, j};
            neighbors.push_back(c);
        }
        if(j > 0 && matrix[i][j-1] > currentCellValue){
            Cell c = {i, j - 1};
            neighbors.push_back(c);
        }
        if(i < matrix.size()-1 && matrix[i+1][j] > currentCellValue){
            Cell c = {i+1, j};
            neighbors.push_back(c);
        }
        if(j < matrix[i].size()-1  && matrix[i][j + 1] > currentCellValue){
            Cell c = {i, j + 1};
            neighbors.push_back(c);
        }
        return neighbors;
        
    }
    
    int findLongestPath( vector<vector<vector<Cell>>>& graph, int startI, int startJ, int level,  vector<vector<int>>& dp){
        

        if(dp[startI][startJ] != -1)
            return dp[startI][startJ];
        vector<Cell> neighbors = graph[startI][startJ];

        int maxPathFrom = 0;
        for(Cell neighbor: neighbors){
            maxPathFrom = max(maxPathFrom, findLongestPath(graph, neighbor.i, neighbor.j, level + 1, dp) + 1) ;
        }
        dp[startI][startJ] = maxPathFrom;
        return maxPathFrom;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<vector<Cell>>> increasingGraph(n, vector<vector<Cell>>(m));
        for(int i = 0; i < n; i++){
             for(int j = 0; j < m; j++){
                 vector<Cell> neighbors = getIncreasingNeighbors(matrix, i, j);
                 increasingGraph[i][j] = neighbors;
             }
        }
    
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxPath = -1;
        for(int i = 0; i < n; i++){
             for(int j = 0; j < m; j++){
                  int currentPath = 0;
                  if(dp[i][j] != -1)
                    currentPath = dp[i][j];
                 else
                    currentPath = findLongestPath(increasingGraph, i,j, 0, dp);
                 if(currentPath > maxPath)
                     maxPath = currentPath;
             }
        }
        
        return maxPath + 1;

        
    }
};