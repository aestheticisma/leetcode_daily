class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = sorted(map(str, nums), key = cmp_to_key(lambda x, y: int(y+x)-int(x+y)))
        return "0" if nums[0]=='0' else "".join(nums)