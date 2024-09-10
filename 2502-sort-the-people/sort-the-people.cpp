class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int,string>>v;
        
        for(int i=0;i<heights.size();i++){
            v.push_back({heights[i],names[i]});
        }
        sort(v.rbegin(),v.rend());


        for(int i=0; i<v.size(); i++){
            ans.push_back(v[i].second);
        }

        return ans;
    }
};