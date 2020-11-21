# 使用哈希表，字母异位词一定是字符种类和数量相同的词
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        ans1, ans2 = {}, {}
        for ch1, ch2 in zip(s, t):
            if ch1 not in ans1:
                ans1[ch1]= 1
            else: ans1[ch1] += 1
            
            if ch2 not in ans2:
                ans2[ch2] = 1
            else: ans2[ch2] += 1
        return ans1 == ans2