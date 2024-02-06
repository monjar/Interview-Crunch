//https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3068/

class Solution {
public:
    
    
    unordered_map<string, vector<string>> getWordGraph(string beginWord, string endWord, vector<string>& wordList){
        unordered_map<string, vector<string>> wordLadderGraph;
        
        wordList.push_back(beginWord);
        for(string word : wordList){
            vector<string> neighbors;
            wordLadderGraph[word] = neighbors;
        }
        
        for(string word : wordList)
            for(int charAscii = (int)'a' ; charAscii <= (int)'z'; charAscii++)
                for(int i = 0; i < word.length(); i++){
                    string adjecentWord = word;
                    if(adjecentWord[i] == (char)charAscii)
                        continue;
                    adjecentWord[i] = (char)charAscii;
                    if(wordLadderGraph.count(adjecentWord) != 0)
                        wordLadderGraph[word].push_back(adjecentWord);
                    
                }
            
        
        
        return wordLadderGraph;
        
        
    }
    
    
    
    int findShortestPathInGraph(string beginWord, string endWord,  unordered_map<string, vector<string>> wordLadderGraph){
               
        queue<pair<string, int>> bfsQueue;
        unordered_map<string, bool> visited;

        pair<string, int> beginWordPair(beginWord, 0);
        bfsQueue.push(beginWordPair);
        int foundPathLength = -1;
        while(!bfsQueue.empty() && foundPathLength == -1){
            pair<string, int> current = bfsQueue.front();
            bfsQueue.pop();
            vector<string> neighbors = wordLadderGraph[current.first];
            for(string neighbor : neighbors){
                if(visited.count(neighbor) == 0){
                    pair<string, int> neighborPair(neighbor, current.second + 1);
                    visited[neighbor] = true;
                    if(neighbor == endWord){
                        foundPathLength = neighborPair.second;
                        break;
                    }
                    bfsQueue.push(neighborPair);
                }
            }
        }
        
        return foundPathLength + 1; 
    }
    
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto wordLadderGraph = getWordGraph(beginWord, endWord, wordList);
        return findShortestPathInGraph(beginWord, endWord, wordLadderGraph); 
    }
};