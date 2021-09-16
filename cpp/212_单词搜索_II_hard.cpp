class Trie {
public:
    vector<Trie*> children;
    string word;
    Trie(): children(26), word("") {}
    void insert(string word) {
        Trie *node = this;
        for (auto ch : word) {
            int i = ch - 'a';
            if (node->children[i] == nullptr)
                node->children[i] = new Trie();
            node = node->children[i];
        }
        node->word = word;
    }
};

class Solution {
private:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root = new Trie();
        set<string> res;
        vector<string> ans;
        for (auto word : words)
            root->insert(word);
        for (int i=0; i<board.size(); i++)
            for (int j=0; j<board[0].size(); j++)
                dfs(board, res, i, j, root);
        for (auto word: res)
            ans.push_back(word);
        return ans;
    }
    bool dfs(vector<vector<char>> &board, set<string> &res, int x, int y, Trie *root) {
        auto ch = board[x][y];
        int i = ch - 'a';
        if (root->children[i] == nullptr) return false;
        root = root->children[i];
        if (root->word.size() > 0)
            res.insert(root->word);
        board[x][y] = '#';
        for (int i=0; i<4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx >=0 && nx < board.size() && ny >=0 && ny < board[0].size())
                if (board[nx][ny] != '#')
                    dfs(board, res, nx, ny, root);
        }
        board[x][y] = ch;
        return true;
    }

};