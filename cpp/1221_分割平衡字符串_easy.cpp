class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, i = 0, j = 0;
        for (auto ch : s) {
            if (ch == 'R')
                i++;
            else
                j++;
            if (i == j) {
                i = 0;
                j = 0;
                ans++;
            }
        }
        return ans;
    }
};