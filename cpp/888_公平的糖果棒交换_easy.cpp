class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int totalA = accumulate(A.begin(), A.end(), 0);
        int totalB = accumulate(B.begin(), B.end(), 0);
        int target = (totalA+totalB)/2;
        vector <int> ans(2);
        unordered_set<int> setB(B.begin(), B.end());
        for (auto a : A) {
            int need = target - totalA + a;
            if (setB.count(need)) {
                ans = vector<int>{a, need};
                break;
            }
        }
        return ans;
    }
};