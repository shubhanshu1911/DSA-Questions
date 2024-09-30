class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> maxHeap;
        
        // Add the first 'k' elements to the heap
        for (int i = 0; i < k; i++) {
            maxHeap.push({nums[i], i});
        }
        ans.push_back(maxHeap.top().first);
        
        // Process the remaining elements in the array
        for (int i = k; i < nums.size(); i++) {
            maxHeap.push({nums[i], i});
            
            // Remove elements from the heap that are out of the current window
            // The current window is from index [i - k + 1] to i
            while (maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }
            
            ans.push_back(maxHeap.top().first);
        }
        
        return ans;
    }
};
