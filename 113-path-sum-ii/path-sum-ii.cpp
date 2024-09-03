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
    void solve(TreeNode* root, int targetSum, int& currSum, vector<int>& path, vector<vector<int>>& ans){
        // Base case 
        if(root == 0)
            return;
        
        // Leaf node
        if(root -> left == 0 && root -> right == 0){
            path.push_back(root -> val);
            currSum += root -> val;
            if(currSum == targetSum){
                ans.push_back(path);
            }
            // backTrack
            path.pop_back();
            currSum -= root -> val;
            return;
        }

        // Include the current node
        path.push_back(root -> val);
        currSum += root -> val;

        solve(root -> left, targetSum, currSum, path, ans);
        solve(root -> right, targetSum, currSum, path, ans);

        // backTrack
        path.pop_back();
        currSum -= root -> val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector <int> temp;
        int currSum = 0;
        solve(root, targetSum, currSum, temp, ans);
        return ans;
    }
};