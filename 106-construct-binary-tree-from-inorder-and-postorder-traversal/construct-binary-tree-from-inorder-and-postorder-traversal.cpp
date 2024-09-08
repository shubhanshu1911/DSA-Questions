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

    TreeNode* buildTreeUsingPostIn (vector<int>& inOrder, vector<int>& postOrder, int size, int& postIndex, int inOrderStart, int inOrderEnd) {
        // BASE CASE 
        if(postIndex < 0 || inOrderStart > inOrderEnd){
            return NULL;
        }

        // Step A : 
        int element = postOrder[postIndex];
        postIndex--;
        TreeNode* root = new TreeNode(element);

        int pos = findPosition(inOrder, size, element);

        // Step B : Right ko solve krro 
        root -> right = buildTreeUsingPostIn(inOrder, postOrder, size, postIndex, pos+1, inOrderEnd);
        
        // Step C : Left ko solve krro
        root -> left = buildTreeUsingPostIn(inOrder, postOrder, size, postIndex, inOrderStart, pos-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        int postIndex = size-1; 
        int inOrderStart = 0;
        int inOrderEnd = size -1;

        TreeNode* root = buildTreeUsingPostIn(inorder, postorder, size, postIndex, inOrderStart, inOrderEnd);
        return root;
        
    }
};