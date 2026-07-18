class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long n = candies.size();
        long long maxi = INT_MIN;
        long long low = 1;
        for(int i = 0; i <= n-1; i++ ){
            maxi = max(maxi , (long long)candies[i]);
        }
        long long high = maxi;
        long long ans = 0;
        while(high >= low){
            long long mid = low + (high - low)/2;
            long long sum = 0;
            for(auto it : candies){
                long long group = it/mid;
                sum = sum + group;
            }
            if(sum >= k ){
                ans = mid;
                low = mid + 1;
            }
            else{
                
                high = mid-1;

            }

        }
        return ans;
    }
};