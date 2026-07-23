class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxSum = 0;
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++ ){
            maxi = max(maxi , weights[i]);
            maxSum += weights[i];
        }
        int high = maxSum;
        int low = maxi;
        while(high >= low){
            int mid = low + (high - low)/2;
            int sum = 0;
            int day = 0;
            for(int i = 0; i < n; i++){
                if(sum + weights[i] <= mid){
                    sum = sum + weights[i];
                }
                else{
                    day = day + 1;
                    sum = weights[i];
                }
            }
            if(day >= days){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};