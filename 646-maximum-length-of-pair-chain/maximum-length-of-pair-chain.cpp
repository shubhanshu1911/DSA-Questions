class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort pairs by the second element in ascending order
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1;
        int n = pairs.size();
        int lastDept = pairs[0][1]; // Start with the first pair's departure time
        
        for (int i = 1; i < n; i++) {
            int currArr = pairs[i][0]; // Current pair's arrival time
            if (currArr > lastDept) { // If current pair can follow the last included pair
                count++;
                lastDept = pairs[i][1]; // Update the last departure time to current pair's
            }
        }

        return count;
    }
};
