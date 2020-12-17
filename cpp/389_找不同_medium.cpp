class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> wordMap;
        for(char _s : s)
            if(wordMap.find(_s) == wordMap.end())
                wordMap[_s] = 1;
            else
                wordMap[_s]++;
        for(char _t : t)
            if(wordMap.find(_t) == wordMap.end())
                return _t;
            else{
                wordMap[_t]--;
                if(wordMap[_t]<0)
                    return _t;
            }
        return ' ';
    }
};

// 法2: 
class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for(char _s : s)
            res ^= _s;
        for(char _t : t)
            res ^= _t;
        return char(res);
    }
};