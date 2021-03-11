class Solution:
    def calculate(self, s: str) -> int:
        n, stk = len(s), []
        num, i = 0, 0
        preSign = '+'
        while i<n:
            while i<n and s[i]==' ':
                i+=1
            while i<n and s[i]>='0' and s[i]<='9':
                num = num*10 + (ord(s[i])-ord('0'))
                i+=1
            if preSign == '+':
                stk.append(num)
            elif preSign == '-':
                stk.append(-num)
            elif preSign == '*':
                stk[-1] *= num
            elif preSign == '/':
                stk[-1] = abs(stk[-1])//num if stk[-1]>=0 else -(abs(stk[-1])//num)
            while i<n and s[i]==' ':
                i+=1
            if (i<n):
                preSign = s[i]
                i+=1
            num = 0
        return sum(stk)