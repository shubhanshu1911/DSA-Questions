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
    bool solve(TreeNode* root, long long int lb, long long int ub){
        // base case 
        if(root == 0) return true;

        // root -> data range me nhi h toh return false 
        if(root -> val <= lb || root -> val >= ub){
            return false;
        }

        // Root range h to check left and rigght 
        bool leftAns = solve(root -> left, lb, root -> val);
        bool rightAns = solve(root -> right, root-> val, ub);
        return leftAns && rightAns;
    }

    bool isValidBST(TreeNode* root) {
        long long int lowerBound = LONG_MIN;
        long long int upperBound = LONG_MAX;
        bool ans = solve(root, lowerBound, upperBound);
        return ans;
    }
};