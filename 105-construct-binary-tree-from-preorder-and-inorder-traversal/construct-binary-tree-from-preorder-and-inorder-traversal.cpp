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
    int findPosition(vector<int> v, int n, int element){
        for(int i=0; i<n; i++){
            if(v[i] == element){
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTreeUsingPreIn (vector<int>& inOrder, vector<int>& preOrder, int size, int& preIndex, int inOrderStart, int inOrderEnd) {
        // BASE CASE 
        if(preIndex >= size || inOrderStart > inOrderEnd){
            return NULL;
        }

        // Step A : 
        int element = preOrder[preIndex++];
        TreeNode* root = new TreeNode(element);
        int pos = findPosition(inOrder, size, element);

        root -> left = buildTreeUsingPreIn(inOrder, preOrder, size, preIndex, inOrderStart, pos-1);
        root -> right = buildTreeUsingPreIn(inOrder, preOrder, size, preIndex, pos+1, inOrderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int preIndex = 0; 
        int inOrderStart = 0;
        int inOrderEnd = size -1;

        TreeNode* root = buildTreeUsingPreIn( inorder, preorder, size, preIndex, inOrderStart, inOrderEnd);
        return root;
    }
};