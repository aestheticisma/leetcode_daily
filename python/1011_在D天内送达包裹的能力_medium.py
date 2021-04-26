class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        left, right = max(weights), sum(weights)
        while left < right:
            mid = (left + right) >> 1
            need, cur = 1, 0
            for w in weights:
                if cur + w > mid:
                    cur = 0
                    need += 1
                    if need > D:
                        break
                cur += w
            if need > D:
                left = mid + 1
            else:
                right = mid
        return left
