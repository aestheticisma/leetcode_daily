class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> strMaps;
        unordered_map<char, char> strMapt;
        int N = s.length();
        for(int i=0; i<N; i++){
            char x = s[i], y = t[i];
            if((strMaps.count(x) && strMaps[x]!=y) || strMapt.count(y) && strMapt[y] != x)
                return false;
            strMaps[x] = y;
            strMapt[y] = x;
        }
        return true;
    }
};