class Solution:
    def numDecodings(self, s: str) -> int:
        if not len(s) or s[0] == '0':
            print(111)
            return 0
        dp = [0 for i in range(len(s)+1)]
        dp[0], dp[1], flag = 1, 1, 1
        for i in range(2, len(s)+1):
            if dp[i-1] == 0:
                return 0
            elif s[i-1] == '0':
                if flag and int(s[i-1-1]+s[i-1]) <= 26:
                    dp[i] = dp[i-2]
                    flag = 0
                else:
                     dp[i] = 0
            else:
                if flag and int(s[i-1-1]+s[i-1]) <= 26:
                    dp[i] = dp[i-1] + dp[i-2]
                else:
                    dp[i] = dp[i-1]
                flag = 1
        print(dp)
        return dp[len(s)]
            


        
        