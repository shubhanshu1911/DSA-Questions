class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int, int>> temp;

        // Create a vector of pairs (element, index)
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back({nums[i], i});
        }
         
        sort(temp.begin(), temp.end());

        int s =0;
        int e = temp.size()-1;

        while(s < e){
            int sum = temp[s].first + temp[e].first;

            if(sum == target) {
                ans.push_back(temp[s].second);
                ans.push_back(temp[e].second);
                break;
            }

            if(sum > target) e--;
            
            else s++;
        } 
        return ans;
        
        
        
        
        
        
        // vector<int> ans;
        // // int sum = 0;
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         int sum = nums[i] + nums[j];
        //         if(sum == target) {
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;
    }
};