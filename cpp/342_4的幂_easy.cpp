class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0 || n & (n-1)) return false;
        int cnt = 0;
        while (n) {
            cnt++;
            n = n >> 1;
        }
        return cnt % 2 ? true : false;
    }
};