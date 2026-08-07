class Solution {
public:
    bool solve(int i ,vector<vector<int>>& dp , vector<int>& nums ,int target){
        if(i == nums.size() ){
            if(target == 0){
                return true;
            }
            else{
               return false;
            }
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        bool notake = solve(i + 1, dp, nums, target);
        bool take = false;
        if(target >= nums[i]){
            take = solve(i + 1 , dp , nums, target - nums[i]);
        }

        return dp[i][target] = (take || notake );

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(n , vector<int>(target+1 , -1));
        return solve(0 , dp , nums, target );
        
    }
};