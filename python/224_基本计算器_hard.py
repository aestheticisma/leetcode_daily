class Solution:
    def calculate(self, s: str) -> int:
        ops, ret, sign, i, n = [1], 0, 1, 0, len(s)
        while i < n:
            if s[i] == ' ':
                i += 1
            elif s[i] == '+':
                sign = ops[-1]
                i += 1
            elif s[i] == '-':
                sign = -ops[-1]
                i += 1
            elif s[i] == '(':
                ops.append(sign)
                i += 1
            elif s[i] == ')':
                ops.pop()
                i += 1
            else:
                num = 0
                while i < n and s[i] >= '0' and s[i] <= '9':
                    num = num*10 + (ord(s[i]) - ord('0'))
                    i += 1
                ret += sign * num
        return ret
        