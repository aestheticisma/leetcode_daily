class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def merge_count(left, right):
            if left == right:
                return 0;
            mid = (left+right)//2;
            res_left = merge_count(left, mid)
            res_right = merge_count(mid+1, right)
            res = res_left + res_right
            i, j = left, mid+1
            while(i<=mid):
                while(j<=right and nums[i]>2*nums[j]):
                    j+=1
                res += j-mid-1
                i += 1
            sorted_list = sorted(nums[left:right+1])
            for i in range(len(sorted_list)):
                nums[left+i] = sorted_list[i]
            return res
        if len(nums)<2:
            return 0
        return merge_count(0, len(nums)-1)