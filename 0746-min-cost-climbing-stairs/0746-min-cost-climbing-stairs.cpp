class Solution {
    int n;
public:
    int minCost(vector<int>& cost , int i , vector<int> &dp){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        return dp[i] = cost[i] + min(minCost(cost , i+1, dp) , minCost(cost , i+2 ,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
         n = cost.size();
         vector<int> dp(n , -1);
        int ans = min(minCost(cost , 0, dp) , minCost(cost , 1 ,dp));
        return ans;
   
    }


};