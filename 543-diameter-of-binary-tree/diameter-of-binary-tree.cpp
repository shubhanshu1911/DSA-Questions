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
    int maxDepth(TreeNode* root) {
        // base case 
        if(root == NULL){
            return 0;
        }

        int leftHeight = maxDepth(root -> left);
        int rightHeight = maxDepth(root -> right);

        int maxHeight = max(leftHeight, rightHeight) + 1;
        return maxHeight; 
    }

    int diameterOfBinaryTree(TreeNode* root) {
       if(root == NULL){
        return 0;
       } 

       int opt1 = diameterOfBinaryTree(root -> left);
       int opt2 = diameterOfBinaryTree(root -> right);
       int opt3 = maxDepth(root -> left) + maxDepth(root -> right);

       return max(opt1, max(opt2, opt3));
    }
};