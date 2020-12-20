class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        flag, nums = [0 for i in range(26)], [0 for j in range(26)]
        stack = []
        for ch in s:
            nums[ord(ch)-ord('a')] += 1
        for ch in s:
            if not flag[ord(ch)-ord('a')]:
                while stack and stack[-1] > ch:
                    if nums[ord(stack[-1]) - ord('a')] > 0:
                        flag[ord(stack[-1]) - ord('a')] = 0
                        stack.pop()
                    else:
                        break
                stack.append(ch)
                flag[ord(stack[-1]) - ord('a')] = 1
            nums[ord(ch) - ord('a')] -= 1
        return ''.join(stack)