/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool solve(TreeNode* root, int targetSum, int& currSum){
        if(root == 0){
            return false;
        }

        // Leaf node 
        if(root -> left == 0 && root -> right == 0){
            currSum += root -> val;
            if(currSum == targetSum){
                return true;
            }

            currSum -= root -> val;
            return false;
        }

        // Normal node 
        currSum += root -> val;

        bool leftPart = solve(root -> left, targetSum, currSum);
        bool rightPart = solve(root -> right, targetSum, currSum);

        currSum -= root -> val;
        return leftPart || rightPart;
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        return solve(root, targetSum, currSum);
        
    }
};