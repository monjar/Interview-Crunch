//https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/331/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        
        for(int i = 0; i <  equations.size(); i++){
            string node1 = equations[i][0];
            string node2 = equations[i][1];
            double edge1to2 = values[i];
            graph[node1].push_back(pair<string, double>(node2, edge1to2));
            graph[node2].push_back(pair<string, double>(node1, 1.0/edge1to2));
        }
        
        vector<double>results;
        for(vector<string>query : queries){
            string startNode = query[0];
            string endNode = query[1];
            if(graph.count(startNode) == 0 || graph.count(endNode) == 0){
                results.push_back(-1.0);
                continue;
            }
            
            double result = -1;
            queue<pair<string, double>> bfsQueue;
            bfsQueue.push(pair<string, double>(startNode, 1));
            unordered_set<string> visited;
            while(!bfsQueue.empty()){
                pair<string, double> currentNode = bfsQueue.front();
                bfsQueue.pop();
                if(currentNode.first == endNode){
                    result = currentNode.second;
                    break;
                }
                for(pair<string, double> child :  graph[currentNode.first]){
                    if(visited.count(child.first) != 0)
                        continue;
                    pair<string, double> childEdgePair(child.first, child.second * currentNode.second);
                    bfsQueue.push(childEdgePair);
                }
                visited.insert(currentNode.first);

            }
            results.push_back(result);
        }
        return results;

    }
};