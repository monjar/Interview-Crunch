
// https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3069/
class Solution {
public:
    
    vector<pair<int,int>> getNeghborsInGrid(vector<vector<char>>& grid, int row, int col){
        vector<pair<int,int>> neighbors;
        if(row > 0 && grid[row-1][col] == '1')
            neighbors.push_back(pair<int,int>(row-1, col));
        
        if(row < grid.size()-1 && grid[row+1][col] == '1')
            neighbors.push_back(pair<int,int>(row+1, col));
        
        if(col > 0 && grid[row][col-1] == '1')
            neighbors.push_back(pair<int,int>(row, col-1));
        
        if(col < grid[0].size()-1 && grid[row][col+1] == '1')
            neighbors.push_back(pair<int,int>(row, col+1));
        
        return neighbors;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        int islandsNum = 0;
        for(int i = 0; i < grid.size(); i ++){
            for(int j = 0; j < grid[i].size(); j ++){
                

                if(visited[i][j])
                    continue;
                
                if(grid[i][j] == '0'){
                    visited[i][j] = true;
                    continue;
                }
                
                queue<pair<int, int>> bfsQueue;
                bfsQueue.push(pair<int, int>(i, j));
                visited[i][j] = true;
                while(!bfsQueue.empty()){
                    pair<int, int> current = bfsQueue.front();
                    bfsQueue.pop();
                    vector<pair<int,int>> neighbors = getNeghborsInGrid(grid, current.first, current.second);
                    
                    for(pair<int,int> neighbor : neighbors){
                        if(visited[neighbor.first][neighbor.second])
                            continue;
                        
                        visited[neighbor.first][neighbor.second] = true;
                        
                        bfsQueue.push(neighbor);
                        
                    }
                }
                islandsNum++;
            } 
        }
        return islandsNum;
        
    }
};