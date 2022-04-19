#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0, ans = 0;
        vector<int> levels(n+1);
        while (pos < n) {
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                ++pos;
                ++depth;
            }
            int len = 0;
            bool isFile = false;
            while (pos < n && input[pos] != '\n') {
                if (input[pos] == '.') isFile = true;
                ++pos;
                ++len;
            }
            ++pos;
            if (depth > 1) len += levels[depth-1] + 1;
            if (isFile) ans = max(ans, len);
            else levels[depth] = len;
        }
        return ans;
    }
};