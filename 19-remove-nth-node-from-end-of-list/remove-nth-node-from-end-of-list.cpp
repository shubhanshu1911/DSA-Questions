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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        int i =1;
        ListNode* curr = head;

        // get the length of the LL
        while (curr != NULL) {
            curr = curr->next;
            len++;
        }
        curr = head;

        if(len == 1) {
            return NULL;
        }
        
        if(len == n){
            // delete at head
            ListNode* temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;

            return head;
        }

        if (n == 1) {
            // last node delete krna h
            while (i < len - n) {
                curr = curr->next;
                i++;
            }

            ListNode* temp = curr->next;
            curr->next = NULL;
            delete temp;

            return head;

        }
        // delete at middle
            // put the tail before the nth node
            while (i < len - n) {
                curr = curr->next;
                i++;
            }

            // remove the nth node
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        

        return head;
    }
};