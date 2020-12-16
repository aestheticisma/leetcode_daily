class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        sell, buy = 0, -prices[0]
        for i in range(1, len(prices)):
            _sell = max(sell, prices[i]+buy-fee)
            _buy = max(buy, sell-prices[i])
            sell, buy = _sell, _buy
        return sell