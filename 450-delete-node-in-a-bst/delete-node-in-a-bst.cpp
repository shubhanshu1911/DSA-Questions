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
    int maxValue(TreeNode* root){
        TreeNode* temp = root;
        if(temp == NULL)
            return -1;

        while(temp -> right != NULL){
            temp = temp -> right;
        }
        return temp -> val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case 
        if(root == NULL){
            return NULL;
        }

        if(root -> val == key){
            // iski ko delete krna
            if(root -> left == NULL && root -> right == NULL){
                // leaf node 
                delete root;
                return NULL;
            } 
            else if(root -> left == NULL && root -> right != NULL){
                TreeNode* child = root -> right;
                delete root;
                return child;
            }
            if(root -> left != NULL && root -> right == NULL){
                TreeNode* child = root -> left;
                delete root;
                return child;
            }
            else{
                // dono child exist krte h 
                // inorder preceesor se replace kr denge -> left substree ka max value 
                int inorderPre = maxValue(root -> left);
                root -> val = inorderPre;
                root -> left = deleteNode(root -> left, inorderPre);
                return root;
            }
        }
        else if( key > root -> val ){
            // right me jana h 
            root -> right = deleteNode(root -> right, key);
        }
        else if( key < root -> val ){
            // left me jana h 
            root -> left = deleteNode(root -> left, key);
        }
        return root;
    }
};