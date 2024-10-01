class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> mini(nums.size(), 0);
        vector<long long> maxi(nums.size(), 0);
        long long ans = LLONG_MAX;

        // mini possible sum of n elements from the first part
        long long sum = 0;
        priority_queue<long long> maxHeap; 
        for(int i = 0; i < nums.size(); i++) {
            maxHeap.push(nums[i]);
            sum += nums[i];

            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop(); // coz meko mini sum chahiye -> jo ki bottom two denge
            }

            if (maxHeap.size() == n) {
                mini[i] = sum; // Store sum of smallest n elements
            }
        }

        // max possible sum of n elements from the last part
        sum = 0;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for (int i = nums.size() - 1; i >= 0; i--) {
            minHeap.push(nums[i]);
            sum += nums[i];

            if (minHeap.size() > n) {
                sum -= minHeap.top(); 
                minHeap.pop(); // coz meko max sum chahiye -> jo ki bottom two denge
            }

            if (maxHeap.size() == n) {
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
