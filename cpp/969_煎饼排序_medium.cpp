class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        for (int n = arr.size(); n > 1; --n) {
            int index = max_element(arr.begin(), arr.begin() + n) - arr.begin();
            if (index == n-1) continue;
            reverse(arr.begin(), arr.begin() + index + 1);
            reverse(arr.begin(), arr.begin() + n);
            res.push_back(index+1);
            res.push_back(n);
        }
        return res;
    }
};