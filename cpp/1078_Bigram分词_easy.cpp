class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        if (text.empty()) return {};
        stringstream ss(text);
        vector<string> words, ans;
        string word;
        while (ss >> word) words.push_back(word);
        for (int i = 0; i < words.size() - 2; ++i) {
            if (first == words[i] && second == words[i+1])
                ans.push_back(words[i+2]);
        }
        return ans;
    }
};