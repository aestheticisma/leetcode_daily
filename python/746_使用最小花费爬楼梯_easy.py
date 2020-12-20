class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        left, right = cost[0], cost[1]
        for i in range(2, len(cost)):
            right, left = min(left + cost[i], right + cost[i]), right
        return min(left, right)