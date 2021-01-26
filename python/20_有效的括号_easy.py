class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 == 1:
            return False
        stack = []
        strMap = {
            ')': '(',
            ']': '[',
            '}': '{'
        }
        for _s in s:
            if _s in strMap:
                if not stack or stack[-1] != strMap[_s]:
                    return False
                stack.pop()
            else:
                stack.append(_s)
        return True if not stack else False