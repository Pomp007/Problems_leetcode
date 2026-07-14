class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int cnt = nums[0];
        int n = nums.size();
        for(int i = 1 ; i < n  ; i++ ){
            if(nums[i] ==  cnt ){
                count ++;
                }
            
            else{
                count -- ;
                if(count == 0){
                    count = 1;
                    cnt = nums[i];
                }
            }
        }
        int count1 = 0;
        for(int j = 0 ; j < n ; j++){
            if(cnt == nums[j]){
                count1++;
            }
            if(count1 > n/2){
                return cnt;
            }
        }
        return -1;    
    }   
};