class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        return KMP(haystack, needle);
    }
    
    int KMP(string &p, string &q) {
        int i = 0, j = -1;
        int m = p.length(), n = q.length();
        vector<int> next(n, -1);
        while (i < n-1) {
            if (j == -1 || q[i] == q[j]) {
                i++;
                j++;
                next[i] = j;
            }
            else
                j = next[j];
        }
        i = 0, j = 0;
        while (i < m && j < n) {
            if (j == -1 || p[i] == q[j]) {
                i++;
                j++;
            }
            else
                j = next[j];
        }
        if (j == n) return i-j;
        else return -1;
    }
};