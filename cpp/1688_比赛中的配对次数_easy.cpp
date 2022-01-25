class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n / 2) {
            ans += n / 2;
            n = n % 2 == 0 ? n / 2 : n / 2 + 1;
        }
        return ans;
    }
};