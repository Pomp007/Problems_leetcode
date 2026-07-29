class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int count = 1;
        int i = 0;
        int j = 1;
        ans.push_back(s[0]);
        while( j < s.length()){
            if(s[i] != s[j]){
                ans.push_back(s[j]);
                count = 1;
                j++;
                i++;
            }
            if(s[i] == s[j]){
                if(count >= 3){
                    j++;
                    i++;
                }
                else{
                    count++;
                    ans.push_back(s[j]);
                    i++;
                    j++;
                    count++;
                }
            }
        }
        return ans;
    }
};