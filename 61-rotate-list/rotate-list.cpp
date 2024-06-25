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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        ListNode* tail = head;
        ListNode* temp;

        // Calculate the length of the list
        ListNode* current = head;
        int n = 1; // Start at 1 since we are already at head
        while (current->next) {
            current = current->next;
            n++;
        }

        // Calculate the effective number of rotations needed as 
        // rotating a list by its length n times returns the list to its original form.
        k = k % n;

        while (k > 0) {
            // Tail ko second last node par le jao
            while (tail->next->next != NULL) {
                tail = tail->next;
            }

            // Put temp pointer on the last node
            temp = tail->next;

            // temp ko remove from LL
            tail->next = NULL;
            temp->next = head;
            head = temp;

            // update tail
            tail = head;

            k--;
        }
        return head;
    }
};