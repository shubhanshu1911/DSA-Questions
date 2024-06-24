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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector <int> ans(2,-1);
        vector <int> cp;
        ListNode* curr = head -> next;
        ListNode* prev = head;
        int i = 2;

        while(curr != NULL && curr -> next != NULL){
            if(prev -> val < curr -> val && curr -> next -> val < curr -> val || 
                prev -> val > curr -> val && curr -> next -> val > curr -> val){
                // Critical points  
                cp.push_back(i);
            }
            // not a critical point
            prev = curr;
            curr = curr->next;
            i++;
        }

        // after this loop you will get an critical point vector
        if(cp.size() < 2){
            return ans;
        }

        int min_dist = INT_MAX;
        int max_dist = INT_MIN;

        for (int i = 1; i < cp.size(); i++) {
            int distance = cp[i] - cp[i - 1];
            min_dist = min(min_dist, distance);
            max_dist = max(max_dist, cp[i] - cp[0]);
        }

        ans[0] = min_dist;
        ans[1] = max_dist;
        return ans;

    }
};