class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> hash(26, 0);
        for (const char &ch : licensePlate) {
            if (ch == ' ' || (ch >= '0' && ch <='9')) continue;
            int i = ch - 'a';
            if (ch >= 'A' && ch <= 'Z') i += 32;
            ++hash[i];
        }
        string ans = "";
        for (const string & w : words) {
            if (isAnswer(hash, w) &&(ans.empty() || ans.length() > w.length()))
                ans = w;
        }
        return ans;
    }
    bool isAnswer(vector<int> &hash, string word) {
        vector<int> tmp = hash;
        for (const char ch : word) --tmp[ch-'a'];
        if (*max_element(tmp.begin(), tmp.end()) > 0) return false;
        else return true;
    }
};