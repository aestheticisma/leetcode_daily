class Solution {
public:
    int reverse(int x) {
        if (!x) return 0;
        int y = x;
        int ans = 0;
        while (y) {
            if (ans < INT_MIN/10 || ans > INT_MAX/10)
                return 0;
            ans = ans*10 + y%10;
            y /= 10;
        }
        return ans;
    }
};