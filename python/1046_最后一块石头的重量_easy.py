# Author: Fan Zhang
# 手写大顶堆实现

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        N = len(stones)
        if N == 1:
            return stones[-1]
        if N == 2:
            return abs(stones[0]-stones[1])
        maxHeap = []
        for i in range(N+1):
            # 为了好移动，当i==0时设置一个空元素
            if i == 0:
                maxHeap.append(0)
            else:
                self.maxHeapPush(maxHeap, stones[i-1])
        while len(maxHeap)>2:
            y = self.maxHeapPop(maxHeap)
            x = self.maxHeapPop(maxHeap)
            if x!=y:
                self.maxHeapPush(maxHeap, y-x)
        return 0 if len(maxHeap)==0 else maxHeap[-1]

    
    def maxHeapPush(self, maxHeap, stone):
        maxHeap.append(stone)
        length = len(maxHeap)
        i = length - 1
        while(i>1):
            if maxHeap[i] > maxHeap[i>>1]:
                temp = maxHeap[i]
                maxHeap[i] = maxHeap[i>>1]
                maxHeap[i>>1] = temp
            i >>= 1
    
    # pop时用大顶堆的最后一个代替第一个，也就是移动最后一个元素到堆顶，之后使用筛选法重建大顶堆
    def maxHeapPop(self, maxHeap):
        if len(maxHeap) <= 2:
            return maxHeap.pop()
        ans = maxHeap[1]
        maxHeap[1] = maxHeap.pop()
        tmp = maxHeap[1]
        length = len(maxHeap)
        i, j = 1, 2
        while j<length:
            if j != length-1 and maxHeap[j+1] > maxHeap[j]:
                j += 1
            if maxHeap[j] > tmp:
                maxHeap[i] = maxHeap[j]
                i = j
                j = i<<1
            else:
                break
        maxHeap[i] = tmp
        return  ans




