class Solution {
public:
    string reverseOnlyLetters(string s) {
        if (s.empty()) return "";
        int n = s.length();
        int left = 0, right = n-1;
        while (left < right) {
            while (left < right && !isalpha(s[left])) ++left;
            while (left < right && !isalpha(s[right])) --right;
            if (left >= right) break;
            swap(s[left++], s[right--]);
        }
        return s;
    }
};