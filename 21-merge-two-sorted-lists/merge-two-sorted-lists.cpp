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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        ListNode* ans = new ListNode(-1);
        ListNode *mptr = ans;

        // Merge lists while both lists have nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                mptr -> next = list1;
                mptr = list1;
                list1 = list1 -> next;
            } else {
                mptr -> next = list2;
                mptr = list2;
                list2 = list2 -> next;
            }
        }

        // Append the remaining nodes of list1 or list2
        if(list1 != NULL){
            mptr -> next = list1;
        }
        if(list2 != NULL){
            mptr -> next = list2;
        }

        return ans->next; 
    }
};