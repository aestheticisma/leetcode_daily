class Solution:
    def removeDuplicates(self, S: str) -> str:
        stk = list()
        for ch in S:
            if stk and ch == stk[-1]:
                stk.pop()
            else:
                stk.append(ch)
        return ''.join(stk)