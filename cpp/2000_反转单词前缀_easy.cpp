class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0;
        for (const char &c : word) {
            if (c == ch) break;
            ++index;
        }
        if (index >= word.length()) return word;
        else {
            string ans;
            for (int i = index; i >= 0; --i) ans += word[i];
            ans += word.substr(index+1);
            return ans;
        }
    }
};

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = word.find(ch);
        reverse(word.begin(), word.begin()+index+1);
        return word;
    }
};