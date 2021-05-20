class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string, int> cnt;
        for (auto word : words)
            ++cnt[word];
        vector<string> res;
        for (auto [word, n] : cnt)
            res.push_back(word);
        sort(res.begin(), res.end(), [&](const string &a, const string &b){
            return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b];
        });
        res.erase(res.begin()+k, res.end());
        return res;

    }
};