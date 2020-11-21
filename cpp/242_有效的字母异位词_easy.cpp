// 使用哈希表，字母异位词一定是字符种类和数量相同的词

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map <char, int> ans1, ans2;
        for(int i=0; i<s.length(); i++){
            if(ans1.find(s[i]) == ans1.end())
                ans1[s[i]]=1;
            else ans1[s[i]]++;
            if (ans2.find(t[i]) == ans2.end())
                ans2[t[i]]=1;
            else ans2[t[i]]++;
        }
        return ans1 == ans2;
    }
};