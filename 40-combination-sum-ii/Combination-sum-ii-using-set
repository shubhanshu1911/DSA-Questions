class Solution {
public:
    void combinationSum_helper(vector<int>& candidates, int target,vector<int>& v, set<vector<int>>& ans, int index){
        if(target == 0){
            ans.insert(v);
            return;
        }
        if(target < 0){
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            v.push_back(candidates[i]);
            combinationSum_helper(candidates, target - candidates[i], v, ans, i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        combinationSum_helper(candidates, target, v, ans, 0);
        // This line converts the set<vector<int>> ans into a vector<vector<int>> by copying all its elements.
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
