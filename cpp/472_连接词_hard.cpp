// 字典树 + DFS

class Trie {
public:
    vector<Trie *> children;
    bool isEnd;
    Trie() {
        children.resize(26, nullptr);
        isEnd = false;
    }
    void insert(string &word) {
        if (word.empty()) return;
        int n = word.length();
        Trie *node = this;
        for (int i = 0; i < n; ++i) {
            char ch = word[i];
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                node->children[index] = new Trie();
            node = node->children[index];
        }
        node->isEnd = true;
    }
};

class Solution {
private:
    vector<string> ans;
    Trie *trie = new Trie();
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.empty()) return ans;
        sort(words.begin(), words.end(), [&](const string &a, const string &b) {
            return a.length() < b.length();
        });
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            if (word.empty()) continue;
            if (dfs(word, 0)) ans.push_back(word);
            else trie->insert(word);
        }
        return ans;
    }
    bool dfs(string &word, int start) {
        int n = word.length();
        if (start == n) return true;
        Trie *node = trie;
        for (int i = start; i < n; ++i) {
            char ch = word[i];
            int index = ch - 'a';
            node = node->children[index];
            if (node == nullptr) return false;
            if (node->isEnd) {
                if (dfs(word, i+1))
                    return true;
            }
        }
        return false;
    }
};