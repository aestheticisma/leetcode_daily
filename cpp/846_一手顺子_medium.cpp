class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.empty() || groupSize == 1) return true;
        int n = hand.size();
        if (n % groupSize) return false;
        int ans_size = n / groupSize;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) ++cnt[hand[i]];
        int index = 0, k = 0;
        while (index < n && k < ans_size) {
            int cur = hand[index];
            if (cnt[cur] == 0) {
                ++index;
                continue;
            }
            int num = groupSize;
            --cnt[cur];
            while (--num) {
                if (cnt[++cur] > 0) --cnt[cur];
                else return false;
            }
            ++k;
            ++index;
        }
        return k == ans_size;
    }
};