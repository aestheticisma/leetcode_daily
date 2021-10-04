class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if ((int64_t)numerator % denominator == 0) return to_string((int64_t)numerator / denominator);
        int64_t up = abs((int64_t)numerator), down = abs((int64_t)denominator);
        string ans(((numerator < 0) ^ (denominator < 0) ? "-" : "") + to_string(up / down) + ".");
        unordered_map<int64_t, int> hashMap;
        for (int i=ans.size(); up = up % down * 10; i++) {
            if (hashMap.count(up)) {
                ans.insert(begin(ans) + hashMap[up], '(');
                ans.push_back(')');
                break;
            }
            hashMap[up] = i;
            ans.push_back('0' + up / down);
        }
        return ans;
    }
};