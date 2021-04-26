class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = (left + right) >> 1;
            int need = 1, cur = 0;
            for (auto w : weights) {
                if (cur + w > mid) {
                    cur = 0;
                    need++;
                    if (need > D) break;
                }
                cur += w;
            }
            if (need > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};