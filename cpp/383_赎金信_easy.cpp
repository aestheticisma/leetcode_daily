class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        unordered_map<int, int> m;
        for (const char &ch : magazine) {
            int index = ch - 'a';
            ++m[index];
        }
        for (const char &ch : ransomNote) {
            int index = ch - 'a';
            if (m[index] == 0) return false;
            --m[index];
        }
        return true;
    }
};