class Solution {
private:
    const long long mod = 1000000007;
public:
    int numDecodings(string s) {
        auto check1digits = [](char c) -> int {
            if (c == '0') return 0;
            return c == '*' ? 9 : 1;
        };
        auto check2digits = [](char c0, char c1) -> int {
            if (c0 == '*' && c1 == '*') return 15;
            if (c0 == '*') return c1 <= '6' ? 2 : 1;
            if (c1 == '*') {
                if (c0 == '1') return 9;
                if (c0 == '2') return 6;
                return 0;
            }
            return c0 != '0' && (c0 - '0') * 10 + c1 - '0' <= 26;
        };
        int n = s.size();
        long long ans = 0, a = 0, b = 1;
        for (int i=1; i<=n; i++) {
            ans = check1digits(s[i-1])*b % mod;
            if (i > 1) ans = (ans + (long long)a * check2digits(s[i-2], s[i-1])) % mod;
            a = b;
            b = ans;
        }
        return ans;
    }
};