class Solution {
public:
    int getSum(int a, int b) {
        return b ? getSum(a ^ b, uint(a & b) << 1) : a;
    }
};