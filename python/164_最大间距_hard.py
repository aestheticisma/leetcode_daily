class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        N = len(nums)
        if N<2:
            return 0
        buff = [0]*N
        exp = 1
        max_num = max(nums)
        while(max_num>=exp):
            cnt = [0]*10
            for num in nums:
                digit = (num//exp) % 10
                cnt[digit] += 1
            for i in range(0, 9):
                cnt[i+1] += cnt[i]
            for i in range(N-1, -1, -1):
                digit = (nums[i]//exp) % 10
                buff[cnt[digit]-1] = nums[i]
                cnt[digit] -= 1
            # 注意python 列表的复制要用切片，否则会指向同一个内存空间
            nums = buff[:]
            exp *= 10
        ans = -1
        for i in range(0, N-1):
            ans = max(ans, nums[i+1]-nums[i])
        return ans