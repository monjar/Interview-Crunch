//https://leetcode.com/explore/interview/card/google/62/recursion-4/462/

class Solution {
public:
    
    void findWordsFromPos(vector<vector<char>>& board, int i, int j, string currentWord, unordered_set<string>& res, unordered_set<string>& wordsSet, vector<vector<bool>>& visited,  unordered_set<string>& prefexes){
          
        
     

        if(prefexes.find(currentWord) == prefexes.end()){
            return;
        } 
        
        currentWord+=board[i][j];   
        if(prefexes.find(currentWord) == prefexes.end()){
            return;
        } 
        if(wordsSet.find(currentWord) != wordsSet.end())
            res.insert(currentWord);
        visited[i][j] = true;
       
        if(currentWord.length() <10){
            if(i <board.size() - 1 && !visited[i + 1][j])
                findWordsFromPos(board, i + 1, j, currentWord, res, wordsSet, visited, prefexes);
        
            if(i > 0  && !visited[i - 1][j])
                findWordsFromPos(board, i - 1, j, currentWord, res, wordsSet, visited, prefexes);

            if(j <board[i].size() - 1 && !visited[i][j + 1])
                findWordsFromPos(board, i, j + 1, currentWord, res, wordsSet, visited, prefexes);

            if(j > 0  && !visited[i][j - 1])
                findWordsFromPos(board, i, j - 1, currentWord, res, wordsSet, visited, prefexes);
        
        }
        
        
  
        visited[i][j] = false;
        
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        unordered_set <string> wordsSet; 

        unordered_set<string> prefexes;
        for(string word : words){
            string currentPefix = "";
            for(int i = 0; i < word.length(); i++){
                currentPefix+=word[i];
                if(prefexes.find(currentPefix) == prefexes.end())
                    prefexes.insert(currentPefix);
            }
            wordsSet.insert(word);
        }
        
        prefexes.insert("");
        
        unordered_set<string> resSet;
        
        vector<vector<bool>> visited(m, vector<bool>(n));
       
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                findWordsFromPos(board, i, j, "", resSet, wordsSet, visited, prefexes);
            }
        }
        
    vector<string> res;
    res.insert(res.end(), resSet.begin(), resSet.end());
    return res;
        
    }
};