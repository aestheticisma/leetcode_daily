class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        points.sort(key=lambda points:points[1])
        ans = 1
        arrow = points[0][1]
        for ballon in points:
            if ballon[0] > arrow:
                arrow = ballon[1]
                ans += 1
        return ans