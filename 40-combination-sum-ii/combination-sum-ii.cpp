class Solution {
public:
    void combinationSum_helper(vector<int>& candidates, int target,vector<int>& v, vector<vector<int>>& ans, int index){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            // ek baar le liye h to firse nhi lena h 
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            v.push_back(candidates[i]);
            combinationSum_helper(candidates, target - candidates[i], v, ans, i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        combinationSum_helper(candidates, target, v, ans, 0);
        return ans;
    }
};