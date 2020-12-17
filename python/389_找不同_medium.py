class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        wordMap = dict()
        for _s in s:
            if _s not in wordMap:
                wordMap[_s] = 1
            else:
                wordMap[_s] += 1
        for _t in t:
            if _t not in wordMap:
                return _t
            else:
                wordMap[_t] -= 1
                if wordMap[_t] < 0:
                    return _t
        return ''

### 法二：最终答案一定为奇数的那个，因此可以使用位异或运算
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        res = 0
        for _s in s:
            res ^= ord(_s)
        for _t in t:
            res ^= ord(_t)
        return chr(res)