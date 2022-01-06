class Solution {
public:
    int maxDepth(string s) {
        if (s.empty()) return 0;
        stack<int> stk;
        int ans = 0;
        for (const char ch : s) {
            if (ch == '(') {
                stk.push(ch);
                ans = max(ans, (int)stk.size());
            }
            else if (!stk.empty() && ch == ')') {
                stk.pop();
            }
        }
        return ans;
    }
};