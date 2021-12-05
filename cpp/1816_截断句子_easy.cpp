class Solution {
public:
    string truncateSentence(string s, int k) {
        if (!k) return string("");
        int num = 0;
        string ans = string("");
        int index = 0;
        while (index < s.length()) {
            int begin = index;
            ++num;
            while (index < s.length() && s[index++] != ' ');
            int end = index - begin;
            ans += s.substr(begin, end);
            if (num == k) break;
        }
        return index == s.length() ? ans : ans.substr(0, ans.length()-1);
    }
};