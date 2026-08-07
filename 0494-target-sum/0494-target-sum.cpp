class Solution {
public:

    int solve(vector<int>& nums, int n, int target, int sum) {

        // all elements used
        if (n == 0) {
            if (sum == target) {
                return 1;
            }
            else {
                return 0;
            }
        }

        // put - before current number
        int minus = solve(nums, n - 1, target,
                          sum - nums[n - 1]);

        // put + before current number
        int plus = solve(nums, n - 1, target,
                         sum + nums[n - 1]);

        return minus + plus;
    }


    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = 0;

        return solve(nums, n, target, sum);
    }
};