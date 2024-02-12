class Solution {
public:
    void permutation(vector<vector<int>>& ans,vector<int>& nums, int start){
        // base case 
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i] != nums[start]) {
                swap(nums[i], nums[start]);
                permutation(ans, nums, start + 1);
                swap(nums[i], nums[start]);
            }
    }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        permutation(ans, nums, 0);
        
        // copy the ans into set st 
        set<vector<int>> st;
        for(auto k: ans){
            st.insert(k);
        }
        ans.clear();
        for(auto k:st){
            ans.push_back(k);
        }
        return ans;
    }
};