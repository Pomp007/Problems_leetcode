class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(cnt1 == 0 && nums[i] != el2 ){
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1 ){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i]){
                cnt1++;
            }
            else if(el2 == nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int count1 = 0;
        int count2 = 0;
        vector<int> ans;
        for(int i = 0 ; i < nums.size(); i++){
            if(el1 == nums[i]){
                count1++;
            }
            if(el2 == nums[i]){
                count2++;
            }   
        }
        int mini = (nums.size()/3) + 1;
        if(count1 >= mini){
            ans.push_back(el1);
        }
        if(count2 >= mini){
            ans.push_back(el2);
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};