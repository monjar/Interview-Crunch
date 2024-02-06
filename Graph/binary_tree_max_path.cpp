// Question Link: https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3067/
struct NodeSubTreeMaxSum{
    int rightSum = 0;
    int leftSum = 0;
};
class Solution {
public:
    
    NodeSubTreeMaxSum findMaxSums(TreeNode* node, map<TreeNode*, NodeSubTreeMaxSum> &nodeMap){
        NodeSubTreeMaxSum nodeSums;
        
        if(nodeMap.count(node))
            return nodeMap[node];
        
        if(node->left){
            NodeSubTreeMaxSum leftTreeSums = findMaxSums(node->left, nodeMap);
            int leftTreeUncutSum = max(leftTreeSums.leftSum, leftTreeSums.rightSum) +  node->left->val;
            nodeSums.leftSum = max(leftTreeUncutSum, node->left->val);
        }
        if(node->right){
            NodeSubTreeMaxSum rightTreeSums = findMaxSums(node->right, nodeMap);
            int rightTreeUncutSum = max(rightTreeSums.leftSum, rightTreeSums.rightSum) +  node->right->val;
            nodeSums.rightSum =  max(rightTreeUncutSum, node->right->val);
        }
        nodeMap[node] = nodeSums;
        return nodeSums;
            
    }
    int maxPathSum(TreeNode* root) {
        
        map<TreeNode*, NodeSubTreeMaxSum> nodeMap;
        NodeSubTreeMaxSum rootMaxSum = findMaxSums(root, nodeMap);
        
        int maxSum = -1001;
        for (auto const& [node, sums] : nodeMap)
        {
            
            cout<< node->val << " Left: " << sums.leftSum << " Right: " << sums.rightSum << endl;
            int bothSideSum = sums.leftSum + sums.rightSum + node->val;
            int oneSideSum = max(sums.leftSum , sums.rightSum) + node->val;
            int maxNodeSum = max(node->val, max(oneSideSum, bothSideSum));
            maxSum = max(maxSum, maxNodeSum);
        }
        
        return maxSum;
    }
};