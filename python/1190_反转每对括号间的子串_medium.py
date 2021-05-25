class Solution:
    def reverseParentheses(self, s: str) -> str:
        stk = []
        string = ""
        for ch in s:
            if ch == '(':
                stk.append(string)
                string = ""
            elif ch == ')':
                string = ''.join([string[c] for c in range(len(string)-1, -1, -1)])
                string = stk[-1] + string
                stk.pop()
            else:
                string += ch
        return string