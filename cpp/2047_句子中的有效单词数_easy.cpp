class Solution {
public:
    int countValidWords(string sentence) {
        if (sentence.empty()) return 0;
        int left = 0, right = 0, n = sentence.length();
        int cnt = 0;
        while (left < n) {
            while (left < n && sentence[left] == ' ') ++left;
            if (left >= n) break;
            right = left + 1;
            while (right < n && sentence[right] != ' ') ++right;
            if (valid(sentence.substr(left, right - left)))
                ++cnt;
            left = right + 1;
        }
        return cnt;
    }

    bool valid(string word) {
        bool hashyphen = false;
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            if (word[i] >= '0' && word[i] <= '9') return false;
            else if (word[i] == '-') {
                if (hashyphen || i == 0 || i == n-1 || !islower(word[i-1]) || !islower(word[i+1])) {
                    return false;
                }
                hashyphen = true;
            }
            else if (word[i] == '!' || word[i] == '.' || word[i] == ',')
                if (i != n-1) return false;
        }
        return true;
    }
};