class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](const auto &a, const auto &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        stack<int> stk;
        int ans = 0;
        for (const auto &p : properties) {
            while (!stk.empty() && stk.top() < p[1]) {
                ++ans;
                stk.pop();
            }
            stk.push(p[1]);
        }
        return ans;
    }
};