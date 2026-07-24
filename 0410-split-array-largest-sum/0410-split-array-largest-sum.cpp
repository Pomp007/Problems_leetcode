class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int summation = 0;
        for(int i = 0; i < nums.size(); i++){
            maxi = max(maxi , nums[i]);
        }
        for(int i = 0 ; i < nums.size(); i++){
            summation = summation + nums[i];
        }

        int low = maxi;
        int high = summation;
        while(high >= low){
            int mid = low + (high - low)/2;
            int sum = 0;
            int group = 1;
            for( auto it : nums){
                
                if(sum + it <= mid){
                    sum = sum + it;
                }
                else{
                    group = group + 1;
                    sum = it;
                }
            }
            if(group <= k){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }

        }
        return low;


    }   
};