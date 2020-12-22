class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        res = 0
        for i, ch in enumerate(sequence):
            index = 0
            ans = 0
            if ch == word[index]:
                # j, index = i+1, index+1
                j = i
                while(index<len(word) and j<len(sequence)):
                    if sequence[j] == word[index]:
                        j, index = j+1, index+1
                    else:
                        break
                    if index == len(word):
                        ans += 1
                        index = 0
                res = max(res, ans)
        return res