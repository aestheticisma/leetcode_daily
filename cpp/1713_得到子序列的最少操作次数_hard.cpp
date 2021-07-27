class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int tLength = target.size();
        unordered_map <int, int> data;
        for (int i=0; i< tLength; i++)
            data[target[i]] = i;
        vector<int> ans;
        for (auto num : arr) {
            if (data.count(num)) {
                int n = ans.size();
                int value = data[num];
                if (n == 0 || value > ans[n-1])
                    ans.emplace_back(value);
                else {
                    int l = 0, r = n-1;
                    int pos = r;
                    while (l <= r) {
                        int mid = l + (r - l)/2;
                        if (ans[mid] < value)
                            l = mid + 1;
                        else {
                            pos = mid;
                            r = mid - 1;
                        }
                    }
                    ans[pos] = value;
                }
            }
        }
        return tLength - ans.size();
    }
};