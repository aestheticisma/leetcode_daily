// 排序 + 双指针
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        sort(ages.begin(), ages.end());
        int left = 0, right = 0, ans = 0;
        for (const int & age : ages) {
            if (age < 15) continue;
            while (ages[left] <= 0.5 * age + 7) ++left;
            while (right + 1 < n && ages[right + 1] <= age) ++right;
            ans += right - left;
        }
        return ans;
    }
};

// 计数 + 前缀和
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121);
        for (const int & age : ages) ++cnt[age];
        vector<int> pre(121);
        for (int i = 1; i < 121; ++i)
            pre[i] = pre[i-1] + cnt[i];
        int ans = 0;
        for (int i = 15; i < 121; ++i) {
            int bound = 0.5 * i + 8;
            ans += cnt[i] * (pre[i] - pre[bound-1] - 1);
        }
        return ans;
    }
};