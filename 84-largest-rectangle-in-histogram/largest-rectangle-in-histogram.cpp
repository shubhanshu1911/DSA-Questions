class Solution {
public:
    vector<int> prevSmaller(vector<int>&v){
        stack<int> s;
        s.push(-1);

        vector<int> ans(v.size());
        // left to right
        for(int i=0; i<v.size(); i++){
            int curr = v[i];
            while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
            }
            // chote element mil chuka h -> ans me store krdo 
            ans[i] = s.top();
            // curr element ko push krdo stack me
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>&v){
        stack<int> s;
        s.push(-1);

        vector<int> ans(v.size());
        // left to right
        for(int i=v.size()-1; i>=0; i--){
            int curr = v[i];
            while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
            }
            // chote element mil chuka h -> ans me store krdo 
            ans[i] = s.top();
            // curr element ko push krdo stack me
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        // prevSmaller output 
        vector<int> prev = prevSmaller(heights);

        // nextSmaller output
        vector<int> next = nextSmaller(heights);

        int maxArea = INT_MIN;
        // area 
        for(int i=0; i<heights.size(); i++){
            int len = heights[i];

            if(next[i] == -1){
            next[i] = heights.size();
            }
            int width = next[i] - prev [i] -1;

            int area = len * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};