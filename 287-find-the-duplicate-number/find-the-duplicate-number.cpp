class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i]);

            // checking if already marked
            if(nums[index] < 0){
                return index;
            }

            // marking negative
            nums[index] *= -1;
        } 
        return -1;
    }
};