class Solution {
public:
    string sortString(string s) {
        vector<int> freq('z'-'a'+1, 0);
        for(char ch : s)
            ++freq[ch-'a'];
        string ans;
        // ans.reserve(size(s));
        int flag = -1;
        while(flag!=size(ans)){
            flag = size(ans);
            for(char ch='a'; ch<='z'; ch++) if(--freq[ch-'a']>=0) ans+=ch;
            for(char ch='z'; ch>='a'; ch--) if(--freq[ch-'a']>=0) ans+=ch;
        }
        return ans;
    }
};