class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        def possible(k):
            times = 0
            for pile in piles:
                times += (pile-1) // k + 1
            return times <= H

        low, high = 1, 10**9
        while low <= high:
            mid = (low + high) // 2
            if possible(mid):
                high = mid - 1
            else:
                low = mid + 1
        return low