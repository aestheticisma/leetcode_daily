class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for (auto &t : dictionary) {
            int i = 0, j = 0;
            while (i < t.size() && j < s.size()) {
                if (t[i] == s[j]) ++i;
                ++j;
            }
            if (i == t.size()) {
                if (ans.size() == t.size())
                    ans = t > ans ? ans : t;
                else
                    ans = t.size() > ans.size() ? t : ans;
            }
        }
        return ans;
    }
};