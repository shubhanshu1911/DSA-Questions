class compare {
public:
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        int k = lists.size();

        if(k == 0) return NULL;

        // Push the head of each list into the minHeap using a traditional for loop
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (!minHeap.empty()) {
            ListNode* temp = minHeap.top();
            minHeap.pop();

            if (head == nullptr) {
                // First element being added to the merged list
                head = temp;
                tail = temp;
            } else {
                // Append temp to the merged list
                tail->next = temp;
                tail = tail->next;
            }

            // Push the next node of temp into the minHeap
            if (temp->next != nullptr) {
                minHeap.push(temp->next);
            }
        }

        return head;
    }
};
