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

    int bottomUpSolve(int n){
        // Step 1 : Create dp array 
        vector<int> dp(n+1, -1);
        // Step 2 : Obverse base case in above sitution
        dp[0]=0;
        if(n == 0) 
            return dp[0];

        dp[1] = 1;
        if(n == 1) 
            return dp[1];

        // Step 3 : 
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int fib(int n) {
        // step 1 : Create dp array
        // vector<int> dp(n+1, -1);
        // int ans = topDownSolve(n, dp);
        // return ans;

        int ans = bottomUpSolve(n);
        return ans;
        
    }
};