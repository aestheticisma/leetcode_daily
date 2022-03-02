class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while (num || ans / 10) {
            if (num == 0) {
                num = ans;
                ans = 0;
            }
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
};