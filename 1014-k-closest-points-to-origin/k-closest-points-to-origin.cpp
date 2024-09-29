class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> minHeap;
        vector<vector<int>> ans;

        for(int i=0; i<points.size(); i++){
            vector<int> temp = points[i];
            double sd = sqrt((temp[0] * temp[0]) + (temp[1] * temp[1]));  // Correct distance calculation
            minHeap.push(make_pair(sd, temp));  // Pair distance with point and push
        }

        while(k-- && !minHeap.empty()){
            vector<int> topElement = minHeap.top().second;
            minHeap.pop();
            ans.push_back(topElement);
        } 
        return ans;
    }
};