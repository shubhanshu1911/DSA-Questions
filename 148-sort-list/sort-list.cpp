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
    ListNode* findMid(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // LL have more than 1 nodes
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != NULL && fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
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

    ListNode* sortList(ListNode* head) {
        if(head == 0 || head -> next == 0){
            return head;
        }

        // break LL into two halves to using mid node 
        ListNode* midNode = findMid(head);
        ListNode* left = head;
        ListNode* right = midNode -> next;
        midNode -> next = NULL;

        // Sort RE
        left = sortList(left);
        right = sortList(right);

        // merge both left and right
        ListNode* mergedLL = merge(left, right);
        return mergedLL;

    }
};