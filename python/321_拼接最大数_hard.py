class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        def findMaxSeq(nums, k):
            popNum = len(nums)-k
            ans = []
            for i in range(len(nums)):
                while(ans and nums[i]>ans[-1] and popNum > 0):
                    ans.pop()
                    popNum -= 1
                ans.append(nums[i])
            return ans[:k]
        def compare(nums1, nums2):
            n, m = len(nums1), len(nums2)
            k = min(n, m)
            for i in range(k):
                if nums1[i] == nums2[i]:
                    n -= 1
                    m -= 1
                    continue
                elif nums1[i] < nums2[i]:
                    return 0
                else:
                    return 1
            if n:
                return 1
            else:
                return 0

        n, m = len(nums1), len(nums2)
        temp1, temp2 = [], []
        res = [0]*k
        for s in range(max(0, k-m), min(k, n)+1):
            temp1 = findMaxSeq(nums1, s)
            temp2 = findMaxSeq(nums2, k-s)
            temp = []
            while(temp1 and temp2):
                if compare(temp1, temp2):
                    temp.append(temp1.pop(0))
                else:
                    temp.append(temp2.pop(0))
            if temp1: temp += temp1
            elif temp2: temp += temp2
            res = res if compare(res, temp) else temp
        return res