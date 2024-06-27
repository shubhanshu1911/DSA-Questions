/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *currA = headA;
        ListNode *currB = headB;

        // Calculate the length of list A
        int lengthA = 0;
        while (currA != nullptr) {
            lengthA++;
            currA = currA->next;
        }

        // Calculate the length of list B
        int lengthB = 0;
        while (currB != nullptr) {
            lengthB++;
            currB = currB->next;
        }

        // Reset the pointers to the heads of the lists
        currA = headA;
        currB = headB;

        // Align the start of the pointers
        if (lengthA > lengthB) {
            for (int i = 0; i < lengthA - lengthB; i++) {
                currA = currA->next;
            }
        } else {
            for (int i = 0; i < lengthB - lengthA; i++) {
                currB = currB->next;
            }
        }

        // Traverse the lists together until the intersection is found
        while (currA != nullptr && currB != nullptr) {
            if (currA == currB) {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }

        return nullptr;
    }
};
