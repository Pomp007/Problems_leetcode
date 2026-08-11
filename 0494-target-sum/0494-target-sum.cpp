class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for (int x : nums) {
            sum += x;
        }

        if (abs(target) > sum) {
            return 0;
        }

        if ((target + sum) % 2 != 0) {
            return 0;
        }

        int maxSum = (target + sum) / 2;

        vector<vector<int>> dp(n + 1,
                               vector<int>(maxSum + 1, 0));

        // Base case
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= maxSum; j++) {

                // Don't take
                int notake = dp[i - 1][j];

                // Take
                int take = 0;
                if (nums[i - 1] <= j) {
                    take = dp[i - 1][j - nums[i - 1]];
                }

                dp[i][j] = take + notake;
            }
        }

        return dp[n][maxSum];
    }
};