class Solution {
public:
    int numDecodings(string s) {
        if(!s.length() || s[0] == '0')
            return 0;
        vector<int> dp(s.length()+1, 0);
        dp[0] = 1, dp[1] = 1;
        int flag = 1;
        for(int i=2; i<s.length()+1; i++)
            if(dp[i-1]==0)
                return 0;
            else if(s[i-1]=='0')
                if(flag && (10*(s[i-1-1]-'0')+(s[i-1]-'0'))<=26){
                    dp[i] = dp[i-2];
                    flag = 0;
                }
                else
                    dp[i] = 0;
            else{
                if(flag && (10*(s[i-1-1]-'0')+(s[i-1]-'0'))<=26)
                    dp[i] = dp[i-1]+dp[i-2];
                else
                    dp[i] = dp[i-1];
                flag = 1;
            }
        return dp[s.length()];
    }
};