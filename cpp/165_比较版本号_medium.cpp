class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            int x = 0;
            for (; i<n && version1[i] != '.'; i++) {
                x = x * 10 + version1[i] - '0';
            }
            i++;
            int y = 0;
            for (; j<m && version2[j] != '.'; j++) {
                y = y * 10 + version2[j] - '0';
            }
            j++;
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};