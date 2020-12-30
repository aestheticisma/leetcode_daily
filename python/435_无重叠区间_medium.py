class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        intervals.sort(key=lambda x:x[1])
        end = intervals[0][1]
        ans = 0
        for interval in intervals[1:]:
            start = interval[0]
            if start < end:
                ans += 1
            else:
                end = interval[1]
        return ans