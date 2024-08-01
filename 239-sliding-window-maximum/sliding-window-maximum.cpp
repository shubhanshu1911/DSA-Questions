class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque <int> dq;
       vector <int> ans;

        // first k size ki window ko process krna h
        for(int i=0; i<k; i++){
            // current element se chote element ko window se remove krdo
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }

            // inserting index of current element to check out of the window
            dq.push_back(i);

        }

        // ans ko store krlo 
        ans.push_back(nums[dq.front()]);

        // remaining windows ko process krlo 
        for(int i=k; i<nums.size(); i++){
            // out of window remove krro
            if(!dq.empty() && i-dq.front() >= k){
                dq.pop_front();
            }

            // aab firse current element ke liye chote element remove krro
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }

            // inserting index of current element to check out of the window
            dq.push_back(i);

            // ans ko store krlo 
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};