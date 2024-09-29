class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap to store the closest k points based on distance
        priority_queue<pair<double, vector<int>>> maxHeap;
        vector<vector<int>> ans;

        for(int i = 0; i < points.size(); i++){
            // Calculate Euclidean distance
            double sd = sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));

            // Push the distance and point into the max heap
            maxHeap.push({sd, points[i]});

            // If the size of the heap exceeds k, pop the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract k closest points from the heap
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};
