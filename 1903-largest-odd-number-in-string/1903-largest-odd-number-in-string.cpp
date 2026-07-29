class Solution {
public:
    string largestOddNumber(string num) {
        int maxi = 0;
        int index = -1;
        for(int i = 0; i < num.length(); i++){
            int digit = num[i] - '0';
            if(digit %2 != 0){
                maxi = max(maxi , digit);
                index = i;
                
            }
        }
        return num.substr(0 , index + 1);
    }
};