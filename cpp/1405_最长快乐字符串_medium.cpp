class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> arr = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        string ans;
        while (true) {
            sort(arr.begin(), arr.end(), [&](const auto &a, const auto &b){
                return a.first > b.first;
            });
            bool hasNext = false;
            for (auto &[cnt, ch] : arr) {
                if (cnt <= 0) break;
                int m = ans.size();
                if (m >= 2 && ans[m-2] == ch && ans[m-1] == ch) continue;
                ans.push_back(ch);
                --cnt;
                hasNext = true;
                break;
            }
            if (!hasNext) break;
        }
        return ans;
    }
};