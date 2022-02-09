#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        function<int(int, int)> gcd = [&](int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        };
        vector<string> ans;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j < i; ++j)
                if (gcd(i, j) == 1)
                    ans.push_back(to_string(j) + '/' + to_string(i));
        return ans;
    }
};