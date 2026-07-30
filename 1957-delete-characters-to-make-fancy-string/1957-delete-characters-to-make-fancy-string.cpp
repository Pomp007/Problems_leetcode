class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int count = 1;

        ans.push_back(s[0]);

        for (int j = 1; j < s.length(); j++) {

            if (s[j] == s[j - 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count <= 2) {
                ans.push_back(s[j]);
            }
        }

        return ans;
    }
};