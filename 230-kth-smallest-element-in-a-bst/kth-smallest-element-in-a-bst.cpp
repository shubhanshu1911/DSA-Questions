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
    int kthSmallest(TreeNode* root, int& k) {
        // base case 
        if(root == 0) return -1;

        // Inorder traversal 
        // left 
        int leftAns = kthSmallest(root -> left, k);
        // check ki left se ans aa raha h 
        if(leftAns != -1) return leftAns;

        // current node 
        k--;
        if(k==0) return root -> val;

        // right 
        int rightAns = kthSmallest(root -> right, k);
        return rightAns;
        
    }
};