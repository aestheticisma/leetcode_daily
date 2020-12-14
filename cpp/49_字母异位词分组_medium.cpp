class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector <string>> mp;
        for(string &s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto i=mp.begin(); i!=mp.end(); i++)
            ans.push_back(i->second);
        return ans;
    }
};