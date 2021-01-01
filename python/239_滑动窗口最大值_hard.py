# 手写大顶堆实现

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans, maxHeap = [], [(0,0)]
        for i in range(k):
            self.maxHeapPush(maxHeap, (nums[i], i))
        ans.append(maxHeap[1][0])
        for i in range(k, len(nums)):
            self.maxHeapPush(maxHeap, (nums[i], i))
            while maxHeap[1][1] <= i-k:
                self.maxHeapPop(maxHeap)
            ans.append(maxHeap[1][0])
        return ans
    
    def maxHeapPush(self, maxHeap, value):
        maxHeap.append(value)
        length = len(maxHeap)
        i = length - 1
        while i > 1:
            if maxHeap[i][0] > maxHeap[i>>1][0]:
                tmp = maxHeap[i]
                maxHeap[i] = maxHeap[i>>1]
                maxHeap[i>>1] = tmp
            i >>= 1
    
    def maxHeapPop(self, maxHeap):
        if len(maxHeap) <= 2:
            return maxHeap.pop()
        ans = maxHeap[1]
        maxHeap[1] = maxHeap.pop()
        tmp = maxHeap[1]
        i, j = 1, 2
        length = len(maxHeap)
        while j < length:
            if j+1 < length and maxHeap[j][0] < maxHeap[j+1][0]:
                j += 1
            if maxHeap[j][0] > tmp[0]:
                maxHeap[i] = maxHeap[j]
                i, j = j, j<<1
            else:
                break
        maxHeap[i] = tmp
        return ans