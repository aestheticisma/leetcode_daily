class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        inc, des = 0, 0
        N = len(A)
        for i in range(1, N):
            if A[i] > A[i-1] and inc == 0:
                inc += 1
            elif A[i] < A[i-1] and des == 0:
                des += 1
        return False if inc & des else True