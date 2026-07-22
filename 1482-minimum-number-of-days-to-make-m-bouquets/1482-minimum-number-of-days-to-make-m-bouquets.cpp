class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n)
            return -1; 
            
        int maxiel = INT_MIN;
        int miniel = INT_MAX;
        for(int i = 0; i < n; i++ ){
            maxiel = max(maxiel , bloomDay[i]);
            miniel = min(miniel , bloomDay[i]);
        }
    

        int high = maxiel;
        int low = miniel;
        while(low <= high){
            int mid = low + (high - low)/2;
            int count = 0;
            int sum = 0;
            for(auto it : bloomDay){
             if(it <= mid){
                count++;
             }
             else{
                sum += (count/k);
                count = 0;
             }
            }
             sum = sum + (count/k); // this is Because lets say {7,7,7,7,13,11,12 , 7 } when mid = 12 then last element of array remaining count = 1 according to the (if statement) so else will not execute so we have to process it manuall
             if( sum >= m){
                
                high = mid - 1;

             }
             else{
                low = mid + 1;
             }

        }   
        
         return low;
     
        
    }

};