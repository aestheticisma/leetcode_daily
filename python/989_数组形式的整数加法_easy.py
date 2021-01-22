class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        n = len(A)
        ans = []
        for i in range(n-1, -1, -1):
            A[i] += K%10
            K //= 10
            if(A[i]>=10):
                A[i] -= 10
                K += 1
            ans.append(A[i])
        while(K>0):
            ans.append(K%10)
            K //= 10
        res = []
        for i in range(len(ans)-1, -1, -1):
            res.append(ans[i])
        return res