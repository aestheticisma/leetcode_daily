class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) return 0;
        unordered_map<int, int> cnt;
        int maxLen = 0;
        for (const auto & r : rectangles) {
            int l = min(r[0], r[1]);
            maxLen = max(maxLen, l);
            ++cnt[l];
        }
        return cnt[maxLen];
    }
};