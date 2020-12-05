class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        tasks_map = collections.Counter(tasks)
        maxCount = max(tasks_map.values())
        maxSum = sum([1 for i in tasks_map.values() if i==maxCount])
        return max((maxCount-1) * (n+1) + maxSum, len(tasks))