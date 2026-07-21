class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int left = 0;
        int right = 0;
        int maxLength = 0;

        while(right < n){
            if(nums[right] == 0){
                count ++;
            }
            if(count <= k ){
                maxLength = max(maxLength , right - left + 1);
            }
            if(count > k){
                if(nums[left] == 0){
                    count--;
                }
                left++;

            }
            right++;
        }
        return maxLength;
    }
};