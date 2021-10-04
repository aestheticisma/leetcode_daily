class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int cnt = 0;
        for (int i=s.size()-1; i>=0; i--) {
            if (s[i] != '-') {
                ans.push_back(toupper(s[i]));
                cnt++;
                if (cnt % k == 0)
                    ans.push_back('-');
            }
        }
        if (ans.size() > 0 && ans.back() == '-')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};