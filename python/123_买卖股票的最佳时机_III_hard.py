class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        k = min(2, len(prices)//2)
        buy, sell = [0]*(k+1), [0]*(k+1)
        buy[0], sell[0] = -prices[0], 0
        for i in range(1, k+1):
            buy[i] = sell[i] = float('-inf')
        for i in range(1, len(prices)):
            buy[0] = max(buy[0], sell[0]-prices[i])
            for j in range(1, k+1):
                buy[j] = max(buy[j], sell[j]-prices[i])
                sell[j] = max(sell[j], buy[j-1]+prices[i])
        return max(sell)