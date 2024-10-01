class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        priority_queue<int> maxHeap; // For storing the largest n elements for mini
        priority_queue<int, vector<int>, greater<int>> minHeap; // For storing the smallest n elements for max
        vector<long long> mini(nums.size(), 0);
        vector<long long> maxi(nums.size(), 0);
        long long ans = LLONG_MAX;

        // mini possible sum of n elements from the first part
        long long sum = 0;
        for(int i = 0; i < 2 * n; i++) {
            maxHeap.push(nums[i]);
            sum += nums[i];

            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }

            if (i >= n - 1) {
                mini[i] = sum; // Store sum of smallest n elements
            }
        }

        // max possible sum of n elements from the last part
        sum = 0;
        for (int i = nums.size() - 1; i >= n; i--) {
            minHeap.push(nums[i]);
            sum += nums[i];

            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (i <= 2 * n) {
                maxi[i] = sum; // Store sum of largest n elements
            }
        }

        // Calculate the minimum difference
        for (int i = n - 1; i < 2 * n; i++) {
            ans = min(ans, mini[i] - maxi[i + 1]);
        }

        return ans;
    }
};
