class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> cnt;
        auto insert = [&](const string &s) {
            int left = 0, right = 0;
            int n = s.length();
            while (left < n) {
                while (left < n && s[left] == ' ') ++left;
                if (left >= n) break;
                right = left + 1;
                while (right < n && s[right] != ' ') ++right;
                ++cnt[s.substr(left, right-left)];
                left = right + 1;
            }
        };
        insert(s1);
        insert(s2);
        vector<string> ans;
        for (const auto & [key, val] : cnt) {
            if (val == 1) ans.push_back(key);
        }
        return ans;
    }
};