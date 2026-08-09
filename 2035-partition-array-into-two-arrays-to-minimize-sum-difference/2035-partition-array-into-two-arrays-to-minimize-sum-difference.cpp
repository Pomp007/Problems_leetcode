class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int half = n / 2;

        // Split array into two halves
        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        // leftSums[k] = sums of choosing k elements from left half
        // rightSums[k] = sums of choosing k elements from right half
        vector<vector<int>> leftSums(half + 1);
        vector<vector<int>> rightSums(half + 1);

        // Generate all subset sums
        for (int mask = 0; mask < (1 << half); mask++) {

            int sum = 0;
            int count = 0;

            for (int i = 0; i < half; i++) {

                if (mask & (1 << i)) {
                    sum += left[i];
                    count++;
                }
            }

            leftSums[count].push_back(sum);
        }

        // Generate subset sums for right half
        for (int mask = 0; mask < (1 << half); mask++) {

            int sum = 0;
            int count = 0;

            for (int i = 0; i < half; i++) {

                if (mask & (1 << i)) {
                    sum += right[i];
                    count++;
                }
            }

            rightSums[count].push_back(sum);
        }

        // Sort right-side sums
        for (int i = 0; i <= half; i++) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        int totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }

        int ans = INT_MAX;

        // We need exactly half elements in the first group
        for (int countLeft = 0; countLeft <= half; countLeft++) {

            // If we take countLeft from left,
            // we need half-countLeft from right.
            int countRight = half - countLeft;

            for (int leftSum : leftSums[countLeft]) {

                /*
                    We want:

                    selectedSum ≈ totalSum / 2

                    selectedSum = leftSum + rightSum
                */

                double target = (double)totalSum / 2 - leftSum;

                // Find closest rightSum using binary search
                auto& arr = rightSums[countRight];

                auto it = lower_bound(arr.begin(), arr.end(), target);

                // Check the element >= target
                if (it != arr.end()) {

                    int selectedSum = leftSum + *it;

                    int difference =
                        abs(totalSum - 2 * selectedSum);

                    ans = min(ans, difference);
                }

                // Check the element < target
                if (it != arr.begin()) {

                    --it;

                    int selectedSum = leftSum + *it;

                    int difference =
                        abs(totalSum - 2 * selectedSum);

                    ans = min(ans, difference);
                }
            }
        }

        return ans;
    }
};