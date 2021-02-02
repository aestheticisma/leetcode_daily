class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        left, right = 0, 0
        idx = collections.defaultdict(int)
        ans = 0
        countMax = 0
        while right < n:
            idx[ord(s[right])-ord('A')] += 1
            countMax = max(countMax, idx[ord(s[right])-ord('A')])
            right += 1        
            if right-left > countMax + k:
                idx[ord(s[left])-ord('A')] -= 1
                left += 1
            ans = max(ans, right-left)
        return ans