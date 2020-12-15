class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> strList;
        unordered_map<char, string> strMap;
        vector<string> strTemp;
        int j = 0, i = 0;
        for(i=0; i<s.length(); i++){
            if(s[i] == ' '){
                strList.push_back(s.substr(i-j, j));
                j = 0;
                continue;
            }
            j++;
        }
        strList.push_back(s.substr(i-j, i));
        if(pattern.length() != strList.size())
            return false;
        for(int i=0; i<pattern.length(); i++){
            if(strMap.find(pattern[i]) != strMap.end() && strMap[pattern[i]] != strList[i]){
                return false;
            }
            if(findstring(strList[i], strTemp) && strMap.find(pattern[i]) == strMap.end()){
                return false;
            }
            strMap[pattern[i]] = strList[i];
            strTemp.push_back(strList[i]);
        }
        return true;
    }
    bool findstring(string &s, vector<string> &strTemp){
        for(int i=0; i<strTemp.size(); i++)
            if(strTemp[i]==s)
                return true;
        return false;
    }
};