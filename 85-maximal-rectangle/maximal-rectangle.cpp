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

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;  
        int n = matrix.size();
        int m = matrix[0].size();
        
        //matrix ko v me convert krna
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=0; j<m; j++){
                temp.push_back(matrix[i][j] - '0');  // converting char into int
            }
            v.push_back(temp);
        }

        int area = largestRectangleArea(v[0]);
        
        // for other row, we need to sum them add togethor
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                // agr v[i][j] == 1 h to prev row ke sath add krdo 
                if(v[i][j]){
                    v[i][j] += v[i-1][j];
                }
                else{
                    // v[i][j] == 0 toh 0 hi set kr do
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};