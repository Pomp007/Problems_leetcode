class Solution {
public:
    int solve(vector<int> & coins , int amount , vector<vector<int>> &dp, int n){
        if(amount == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }
        if (dp[n][amount] != -1) {
            return dp[n][amount];
        }
        // nottake
        int notake = solve(coins , amount , dp, n-1);

        //take
        int take = 0;
        if(amount >= coins[n]){
            take = solve(coins ,amount - coins[n] ,dp,  n);
        }

        return dp[n][amount] = take + notake;
        
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        return solve(coins , amount , dp, n-1 );
    }
};