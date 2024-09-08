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
    TreeNode* buildTreeUsingPostIn (vector<int>& inOrder, vector<int>& postOrder, int size, int& postIndex, int inOrderStart, int inOrderEnd, unordered_map<int,int>& mapping ) {
        // BASE CASE 
        if(postIndex < 0 || inOrderStart > inOrderEnd){
            return NULL;
        }

        // Step A : 
        int element = postOrder[postIndex];
        postIndex--;
        TreeNode* root = new TreeNode(element);

        int pos = mapping[element];        

        // Step B : Right ko solve krro 
        root -> right = buildTreeUsingPostIn(inOrder, postOrder, size, postIndex, pos+1, inOrderEnd, mapping);
        
        // Step C : Left ko solve krro
        root -> left = buildTreeUsingPostIn(inOrder, postOrder, size, postIndex, inOrderStart, pos-1, mapping);

        return root;
    }

    void createMap(unordered_map<int,int>& mapping, vector<int>& inorder, int n){
        for(int i=0; i<n; i++){
            mapping[inorder[i]] = i;
        }
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        int postIndex = size-1; 
        int inOrderStart = 0;
        int inOrderEnd = size -1;

        unordered_map<int, int> mapping;

        createMap(mapping, inorder, size);

        TreeNode* root = buildTreeUsingPostIn(inorder, postorder, size, postIndex, inOrderStart, inOrderEnd, mapping);
        return root;
        
    }
};