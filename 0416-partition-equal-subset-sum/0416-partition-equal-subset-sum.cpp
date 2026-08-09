class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i= 0;i < n; i++){
            sum = sum + nums[i];
        }
        if(sum %2 != 0){
            return false;
        }
        int find = sum/2;
    
    vector<vector<bool>> dp(n+1 , vector<bool>(find + 1 , false));
    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=find; j++){
            // Not pick
            bool notpick = dp[i-1][j];

            // pick
            bool take = false;
            if(nums[i-1] <= j){
            take = dp[i-1][j - nums[i-1]];
            }
            // Saving into DP
            dp[i][j] = take || notpick;

        }
    }
    return dp[n][find];
    }
};