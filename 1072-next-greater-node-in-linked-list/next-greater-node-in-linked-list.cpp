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
    vector<int> nextLargerNodes(ListNode* head) {
        int len =0;
        ListNode* tail = head;
        vector <int> v;

        // finding the length of the LL
        while(tail != NULL){
            len ++;
            v.push_back(tail -> val);
            tail = tail -> next;
        }

        stack <int> s;
        s.push(INT_MAX);
        vector <int> ans(len);

        for(int i=len-1; i>=0; i--){
            int curr = v[i];
            while(curr >= s.top()){
                s.pop();
            }
            // bada element mil chuka h -> ans me store krdo 
            ans[i] = s.top();
            // curr element ko push krdo stack me
            s.push(curr); 
        }

        for(int i=0; i<ans.size(); i++){
            if(ans[i] == INT_MAX) {
                ans[i] = 0;
            }
        }
        return ans;
    }
};