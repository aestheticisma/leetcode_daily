class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices:
            return 0
        N = len(prices)
        k = min(k, N//2)
        buy, sell = [0]*(k+1), [0]*(k+1)
        buy[0], sell[0] = -prices[0], 0
        for i in range(1, k+1):
            buy[i] = float("-inf")
        for i in range(1, N):
            buy[0] = max(buy[0], sell[0]-prices[i])
            for j in range(1, k+1):
                buy[j] = max(buy[j], sell[j]-prices[i])
                sell[j] = max(sell[j], buy[j-1]+prices[i])
        return max(sell)