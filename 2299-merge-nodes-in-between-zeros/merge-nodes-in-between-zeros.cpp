/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum =0;
        ListNode* curr = head -> next;
        ListNode* ansHead = new ListNode();
        ListNode* ansTail = ansHead;

        
        while(curr != NULL){
            if(head -> val != curr -> val){
                sum = curr -> val + sum;
            }
            else {
                // head -> val == curr -> val == 0
                ListNode* temp = new ListNode(sum);
                ansTail -> next = temp;
                ansTail = ansTail -> next;
                
                // update head
                head = curr;
                sum = 0;
            }
            curr = curr -> next;
        }
        return ansHead -> next;
    }
};