class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], minProd = nums[0], result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) 
                swap(maxProd, minProd);  // Swap when negative
            
            maxProd = max(nums[i], nums[i] * maxProd);
            minProd = min(nums[i], nums[i] * minProd);
            
            result = max(result, maxProd);
        }
        
        return result;
    }
};
