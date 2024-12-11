class Solution {
public:

    int recSolve(int n){
        // base case 
        if(n==1 || n==0){
            return n;
        }

        int ans = recSolve(n-1) + recSolve(n-2);
        return ans;
    }

    int topDownSolve(int n, vector<int> &dp){
        // base case 
        if(n==1 || n==0){
            return n;
        }
        
        // Step 3 : Check if ans already exist 
        if(dp[n] != -1){
            return dp[n];
        }
        
        // Step 2 : Replace the functions and ans with dp[n]
        dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);
        return dp[n];
    }

    int fib(int n) {
        // step 1 : Create dp array
        vector<int> dp(n+1, -1);
        int ans = topDownSolve(n, dp);
        return ans;
        
    }
};