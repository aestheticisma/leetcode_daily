class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        n, total = len(machines), sum(machines)
        if total % n:
            return -1
        avg = total // n
        ans, sub = 0, 0
        for num in machines:
            num -= avg
            sub += num
            ans = max(ans, abs(sub), num)
        return ans