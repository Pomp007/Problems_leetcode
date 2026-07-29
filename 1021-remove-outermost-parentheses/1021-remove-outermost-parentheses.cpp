class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<char> result;
        int counter = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                if(counter > 0){
                    result.push_back('(');
                }
                counter++;
            }
            else{
                counter--;
                if(counter > 0){
                    result.push_back(')');
                }
            }
        }
        return string(result.begin() , result.end());
    }
};