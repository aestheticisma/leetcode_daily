class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(30):
            cnt = 0
            for num in nums:
                if (num >> i) & 1:
                    cnt += 1
            ans += cnt * (n - cnt)
        return ans