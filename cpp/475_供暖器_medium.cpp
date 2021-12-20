class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        sort(heaters.begin(), heaters.end());
        for (const int &house : houses) {
            int j = binarySearch(heaters, house);
            int i = j - 1;
            int left = i == -1 ? INT_MAX : abs(heaters[i] - house);
            int right = j >= heaters.size() ? INT_MAX : abs(heaters[j] - house);
            ans = max(ans, min(left, right));
        }
        return ans;
    }

    int binarySearch(vector<int> &heaters, int target) {
        int left = 0, right = heaters.size()-1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (heaters[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (heaters[left] < target) return heaters.size();
        else return left;
    }
};