class Solution {
public:
    string toGoatLatin(string sentence) {
        if (sentence.empty()) return "";
        int n = sentence.size();
        unordered_set<char> m = {
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
        };
        auto ok = [&](char ch) { return m.count(ch); };
        int r = 0, l = 0;
        string ans = "";
        string suffix = "a";
        while (r < n) {
            while (r < n && sentence[r] == ' ') ++r;
            while (r < n && sentence[r] != ' ') ++r;
            string word = sentence.substr(l, r - l);
            if (ok(word[0])) {
                word += "ma";
            }
            else {
                int len = word.size();
                word = word.substr(1, len-1) + word[0];
                word += "ma";
            }
            word += suffix;
            ans += word + ' ';
            suffix += "a";
            l = r + 1;
            while (l < n && sentence[l] == ' ') ++l;
        }
        int len = ans.size();
        return ans.substr(0, len-1);
    }
};