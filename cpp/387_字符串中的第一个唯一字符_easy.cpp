class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> strMap;
        for(char ch : s)
            strMap[ch]++;
        for(int i=0; i<s.length(); i++)
            if(strMap[s[i]] == 1)
                return i;
        return -1;
    }
};