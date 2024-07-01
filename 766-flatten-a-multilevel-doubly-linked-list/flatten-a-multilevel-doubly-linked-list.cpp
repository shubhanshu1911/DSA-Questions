class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) { 
            return head;
        }

        Node* curr = head;

        while (curr != NULL) {
            // If current node has a child
            if (curr->child != NULL) {
                Node* forward = curr->next;
                Node* child = flatten(curr->child);

                // Connect current node to the child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;

                // Find the tail of the child list
                Node* childTail = child;
                while (childTail->next != NULL) {
                    childTail = childTail->next;
                }

                // Connect child tail to the next node
                if (forward != NULL) {
                    childTail->next = forward;
                    forward->prev = childTail;
                }
            }

            // Move to the next node
            curr = curr->next;
        }

        return head;
    }
};
