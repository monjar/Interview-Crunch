//https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3070/


class Solution {
public:
    
    
    bool dfs(vector<vector<int>>& graph, int root, vector<bool>& visited, vector<bool>& expanded,vector<int>& order){
        
        if(visited[root])
            return expanded[root];
        
        visited[root] = true;
        expanded[root] = true;
        
        for(int neighbor : graph[root]){
            if(dfs(graph, neighbor, visited, expanded, order))
                return true;
        }
        expanded[root] = false;
        
        order.push_back(root);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for(int i = 0; i < prerequisites.size(); i++){
            vector<int> prerequisite = prerequisites[i];
            graph[prerequisite[0]].push_back(prerequisite[1]);
            
        }
    
        
        vector<bool> visited(numCourses, false);
        vector<bool> expanded(numCourses, false);
        vector<int> topologicalOrder;
        
        
         for(int i = 0; i < numCourses; i++){
            if(dfs(graph, i, visited, expanded, topologicalOrder))
                return vector<int>();
        }
        
        
        
        return topologicalOrder;
        
    }
};