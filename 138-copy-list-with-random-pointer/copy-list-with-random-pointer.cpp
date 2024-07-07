/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* helper(Node* head, unordered_map<Node*, Node*>& mp){
        if(head == 0){
            return 0;
        }

        // Creating a map of old head values and new Head values
        Node* newHead = new Node(head -> val);
        mp[head] = newHead;

        // creating a copy of the LL 
        newHead -> next = helper(head -> next, mp);

        // Linking the same random in new LL as in the old LL
        if(head -> random){
            newHead -> random = mp[head -> random];
        }
        return newHead;         
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        return helper(head, mp);   
    }
};