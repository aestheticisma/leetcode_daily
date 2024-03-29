class Solution {
public:
    int lastRemaining(int n) {
        if (n < 2) return n;
        int a1 = 1;
        int k = 0, cnt = n, step = 1;
        while (cnt > 1) {
            if (k % 2 == 0) {
                a1 += step;
            }
            else {
                a1 = cnt % 2 == 0 ? a1 : a1 + step;
            }
            ++k;
            cnt >>= 1;
            step <<= 1;
        }
        return a1;
    }
};