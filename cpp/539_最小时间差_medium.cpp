class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        if (n > 24 * 60) return 0;
        auto getMinute = [&](const string time) {
            return ((time[0]-'0') * 10 + (time[1] - '0')) * 60 + (time[3] - '0') * 10 + (time[4] - '0');
        };
        sort(timePoints.begin(), timePoints.end());
        int ans = getMinute(timePoints[0]) + 24 * 60 - getMinute(timePoints.back());
        for (int i = 1; i < n; ++i) {
            int cur = getMinute(timePoints[i]) - getMinute(timePoints[i-1]);
            ans = min(ans, cur);
        }
        return ans;
    }
};