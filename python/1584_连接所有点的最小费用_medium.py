class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        N = len(points)
        pq = priority_queue_less(points)
        visit = [0 for i in range(N)]
        ans = 0
        while(pq and N):
            # print(pq.pq)
            (d, p1) = pq.pop()
            if visit[p1]:
                continue
            visit[p1] = 1
            N -= 1
            ans += d
            for p2 in range(len(points)):
                if visit[p2]:
                    continue
                distance = abs(points[p2][0]-points[p1][0])+abs(points[p2][1]-points[p1][1])
                pq.push((distance, p2))
        return ans
            
class priority_queue_less():
    def __init__(self, points):
        self.pq = []
        self.pq.append((-1, -1))
        self.pq.append((0, 0))
        self.num = 1
    def push(self, value):
        self.pq.append(value)
        self.num += 1
        i = self.num
        while(i > 1):
            if self.pq[i][0] < self.pq[i>>1][0]:
                self.pq[i], self.pq[i>>1] = self.pq[i>>1], self.pq[i]
            i >>= 1
    # def top(self):
    #     return self.pq[1]
    def pop(self):
        if self.num == 1:
            self.num -= 1
            return self.pq.pop()
        res = self.pq[1]
        self.pq[1] = self.pq.pop()
        tmp = self.pq[1]
        self.num -= 1
        i, j = 1, 2
        while j <= self.num:
            if j+1<=self.num and self.pq[j][0] > self.pq[j+1][0]:
                j += 1
            if tmp[0] > self.pq[j][0]:
                self.pq[i] = self.pq[j]
                i = j
                j <<= 1
            else:
                break
        self.pq[i] = tmp
        return res
            
            
            

