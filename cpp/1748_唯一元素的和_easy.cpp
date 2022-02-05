class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_set<int> s1, s2;
        int ans = 0;
        for (const int & num : nums) {
            if (s1.find(num) == s1.end()) {
                ans += num;
                s1.insert(num);
            }
            else if (s2.find(num) == s2.end()) {
                ans -= num;
                s2.insert(num);
            }
        }
        return ans;
    }
};