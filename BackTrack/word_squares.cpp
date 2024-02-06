//link: https://leetcode.com/explore/interview/card/google/62/recursion-4/370/

class Solution {
public:
    
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> sqrs;
        
        
        vector<unordered_map<char, vector<string>>> charstartMap; 

        
        for(int j = 0; j < words[0].length(); j++){
            unordered_map<char, vector<string>> mp;
            charstartMap.push_back(mp);
            for(int i = 0; i < words.size(); i++){
           
                charstartMap[j][words[i][j]].push_back(words[i]);
            
            }
            
        }
        
        
        for(int i = 0; i < words.size(); i++){
            
            string firstRowWord = words[i];
            
             if(firstRowWord.length()==1){
                    vector<string> currentList = {firstRowWord};
                    sqrs.push_back(currentList);
                    continue;
            }
            
            for(int j = 0; j < charstartMap[0][firstRowWord[1]].size(); j++){
                string secondRowWord = charstartMap[0][firstRowWord[1]][j];
                
               
                if(secondRowWord[0] != firstRowWord[1])
                    continue;
                
                if(firstRowWord.length()==2){
                        vector<string> currentList = {firstRowWord, secondRowWord};
                        sqrs.push_back(currentList);
                        continue;
                }
                for(int k = 0; k < charstartMap[0][firstRowWord[2]].size(); k++){
                    string thirdRowWord = charstartMap[0][firstRowWord[2]][k];
                    if(thirdRowWord[0] != firstRowWord[2] ||  secondRowWord[2] != thirdRowWord[1])
                        continue;
                    
                    if(firstRowWord.length()==3){
                        vector<string> currentList = {firstRowWord, secondRowWord, thirdRowWord};
                        sqrs.push_back(currentList);
                        continue;
                    }
                    for(int p = 0; p < charstartMap[0][firstRowWord[3]].size(); p++){
                        string forthRowWord = charstartMap[0][firstRowWord[3]][p];
                        if(forthRowWord[0] != firstRowWord[3] ||  secondRowWord[3] != forthRowWord[1] ||                                forthRowWord[2] !=  thirdRowWord[3])
                            continue;
                        
                        vector<string> currentList = {firstRowWord, secondRowWord, thirdRowWord, forthRowWord};
                        sqrs.push_back(currentList);

                    }
            
                }
            }
            
        }
    
        return sqrs;
    }
    
};