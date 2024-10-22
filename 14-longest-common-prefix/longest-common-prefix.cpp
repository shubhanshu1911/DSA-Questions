class TrieNode {
public :
  char data;
  TrieNode* children[26]; // storing the child
  bool isTerminate;
  int childCount;

  TrieNode (char d) {
    this -> data = d;
    // children = new TrieNode[26];
    for(int i=0; i<26; i++){
      children[i] = NULL;
    }
    this -> isTerminate = false;
    this -> childCount = 0;
  }
};

class Solution {
public:
    void insertWord(TrieNode* root, string word){
        // base case 
        if(word.length() == 0){
            // root jo hoga vo terminal hoga 
            root -> isTerminate = true;
            return;
        }

        // ek ko tum insert krro
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            // present h
            child = root -> children[index];
        }
        else{
            // absent h 
            child = new TrieNode(ch);
            root -> childCount++;
            root -> children[index] = child;
        }

        // recursion 
        insertWord(child, word.substr(1));
    }

    void findLCP(string first, string &ans, TrieNode* root){
        // Agr empty string h toh -> Yha me galti krrunga
        if(root -> isTerminate){
            return;
        }

        for(int i=0; i<first.length(); i++){
            char ch = first[i];

            if(root -> childCount == 1){
                ans.push_back(ch);
                int index = ch - 'a';
                root = root -> children[index];
            }
            else break;

            // Terminal node to break kr do
            if(root -> isTerminate) break;
        }
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');

        // insert string
        for(int i=0; i<strs.size(); i++){
            insertWord(root, strs[i]);
        }

        string ans = "";
        string first = strs[0];
        findLCP(first, ans, root);
        return ans;
    }
};