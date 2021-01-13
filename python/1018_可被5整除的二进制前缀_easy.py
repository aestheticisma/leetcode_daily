# 法1:
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        res = []
        for i in range(len(A)):
            if i==0:
                res.append(True if A[0]%5==0 else False)
            else:
                A[i] += A[i-1]*2;
                res.append(True if A[i]%5==0 else False)
        return res

# 法2:
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        res = []
        for i in range(len(A)):
            if i==0:
                res.append(True if A[0]%5==0 else False)
            else:
                mod = (2*(A[i-1]%5)%5+A[i])%5
                if mod == 0:
                    res.append(True)
                else:
                    res.append(False)
                A[i] = mod
        return res