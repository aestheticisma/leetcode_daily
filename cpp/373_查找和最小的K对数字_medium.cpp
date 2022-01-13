// 优先队列
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i)
            pq.push(make_pair(i, 0));
        while (k-- && !pq.empty()) {
            auto [x, y] = pq.top(); pq.pop();
            ans.push_back({nums1[x], nums2[y]});
            if (y + 1 < n) pq.push(make_pair(x, y+1));
        }
        return ans;
    }
};