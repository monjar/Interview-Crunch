//https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3070/

class Solution {
public:
    
    int getFirstMissingChild(TreeNode* root){
       
        if(root->left == nullptr)
            return root->val * 2;
        if(root->right == nullptr)
            return root->val * 2 + 1;          
        return -1;
    }
    
    int countNodesRecursive(TreeNode* root){
       
        vector<TreeNode*> leftHandEdge;
        TreeNode* currentNode = root;
        while(currentNode != nullptr){
            leftHandEdge.push_back(currentNode);
            currentNode = currentNode->left;
        }
        
        for(int i = leftHandEdge.size() - 1; i >=0 ; i--){
            TreeNode* currentLeftRoot = leftHandEdge[i];
            TreeNode* parentNode = currentLeftRoot;
            currentNode = currentLeftRoot->right;
            int level = 0;
            while(currentNode != nullptr){
                level++;
                parentNode = currentNode;
                currentNode = currentNode->right;
            }
            if(level+i == leftHandEdge.size()-1)
                continue;
            return 1 + ((pow(2,  leftHandEdge.size()) - 2)/2) + countNodesRecursive(leftHandEdge[i]->right);
        }
        
        return pow(2,  leftHandEdge.size()) - 1;
    }
    int countNodes(TreeNode* root) {
        return countNodesRecursive(root);
    }
};