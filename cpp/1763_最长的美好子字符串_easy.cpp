class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        int maxPos = 0;
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int lower = 0;
            int upper = 0;
            for (int j = i; j < n; ++j) {
                if (islower(s[j])) {
                    lower |= 1 << (s[j] - 'a');
                } else {
                    upper |= 1 << (s[j] - 'A');
                }
                if (lower == upper && j - i + 1 > maxLen) {
                    maxPos = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(maxPos, maxLen);
    }
};