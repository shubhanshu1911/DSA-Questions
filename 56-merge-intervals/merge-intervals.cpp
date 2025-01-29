class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();

        // Handle empty input
        if (n == 0) return ans;
        
        // Sort intervals by start time
        
        sort(intervals.begin(), intervals.end());

        vector<int> t1 = intervals[0];

        for(int i=1; i<n; i++){
            vector<int> t2 = intervals[i];
            if(t1[1] >= t2[0]){
                t1[0] = min(t1[0], t2[0]);    
                t1[1] = max(t1[1], t2[1]);
            } 
            else{
                ans.push_back(t1);
                t1=t2;
            }
        }

        ans.push_back(t1);

        return ans;
    }
};