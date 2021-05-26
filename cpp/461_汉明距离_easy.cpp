class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int ans = 0;
        while (res) {
            ans++;
            res &= (res-1);
        }
        return ans;
    }
};