class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        ans, n = 0, len(height)
        leftMax, rightMax = [height[0]] + [0]*(n-1), [0]*(n-1) + [height[n-1]]
        for i in range(1, n):
            leftMax[i] = max(leftMax[i-1], height[i])
        for i in range(n-2, -1, -1):
            rightMax[i] = max(rightMax[i+1], height[i])
        ans = sum(min(leftMax[i], rightMax[i]) - height[i] for i in range(n))
        return ans