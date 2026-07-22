class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi , nums[i]);
        }
        int high = maxi;
        int low = 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int sum = 0;
            for(auto it : nums){
                sum = sum + (it + mid - 1)/mid;
            }
            if(sum > threshold){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};