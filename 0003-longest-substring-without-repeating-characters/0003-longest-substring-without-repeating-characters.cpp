class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int maxi = 0;
        unordered_map<char, int> mpp;

        while (r < s.size()) {

            if (mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l) {
                l = mpp[s[r]] + 1;
            }

            mpp[s[r]] = r;          // Store the latest index
            maxi = max(maxi, r - l + 1);

            r++;
        }

        return maxi;
    }
};