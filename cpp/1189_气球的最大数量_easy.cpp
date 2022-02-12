class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if (text.empty()) return 0;
        vector<int> cnt(5);
        for (const char & ch : text) {
            if (ch == 'a') ++cnt[0];
            else if (ch == 'b') ++cnt[1];
            else if (ch == 'l') ++cnt[2];
            else if (ch == 'o') ++cnt[3];
            else if (ch == 'n') ++cnt[4];
        }
        cnt[2] /= 2;
        cnt[3] /= 2;
        return *min_element(cnt.begin(), cnt.end());
    }
};