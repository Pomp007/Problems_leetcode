class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        // Odd total cannot be divided equally
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        // dp[j] = whether sum j can be formed
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            // Traverse backwards so each number is used only once
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};