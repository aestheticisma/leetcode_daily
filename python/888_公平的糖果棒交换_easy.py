class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        totalA = sum(A)
        totalB = sum(B)
        target = (totalA+totalB)//2
        setB = set(B)
        for a in A:
            need = target-totalA+a
            if need in B:
                return [a, need]
        return -1