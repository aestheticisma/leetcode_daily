# 法一：横向扫描

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        def LCS(str1, str2):
            minLen, index = min(len(str1), len(str2)), 0
            for i in range(minLen):
                if str1[i]==str2[i]:
                    index += 1
                else: break
            return str1[:index]

        if len(strs) < 1:
            return ""
        pre = strs[0]
        for i in range(1, len(strs)):
            pre = LCS(pre, strs[i])
            if not pre:
                break
        return pre

# 法三：分治法
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        def divide_strs(start, end):
            if start == end:
                return strs[start]
            mid = (end+start)//2
            preLeft, preRight = divide_strs(start, mid), divide_strs(mid+1, end)
            minLen = min(len(preLeft), len(preRight))
            index = 0
            for i in range(minLen):
                if preLeft[i]!=preRight[i]:
                    break
                index+=1
            return preLeft[:index]
        if not strs:
            return ""
        return divide_strs(0, len(strs)-1) 

# 二分法：根据公共前缀的长度进行二分
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        def isPrefix(length):
            str0 = strs[0][:length]
            for i in range(1, len(strs)):
                stri = strs[i]
                for j in range(length):
                    if str0[j]!=stri[j]:
                        return False
            return True
        if not strs:
            return ""
        minLen = min([len(word) for word in strs])
        low, high = 0, minLen
        while(low<=high):
            mid = (low+high)//2
            if isPrefix(mid):
                low = mid+1
            else:
                high = mid-1
        return strs[0][:low-1]