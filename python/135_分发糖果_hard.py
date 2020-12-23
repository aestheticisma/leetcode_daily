# 法一：
class Solution:
    def candy(self, ratings: List[int]) -> int:
        ins, des, pre = 1, 0, 1
        res = 1
        N = len(ratings)
        for i in range(1, N):
            if ratings[i] >= ratings[i-1]:
                des = 0
                ins = 1 if ratings[i] == ratings[i-1] else pre+1
                res += ins
                pre = ins
            else:
                des += 1
                if des == ins:
                    des += 1
                res += des
                pre = 1
        return res

# 法二：
class Solution:
    def candy(self, ratings: List[int]) -> int:
        N = len(ratings)
        left = [0 for i in range(N)]
        for i in range(N):
            if i>0 and ratings[i]>ratings[i-1]:
                left[i] = left[i-1] + 1
            else:
                left[i] = 1
        right, res = 0, 0
        for i in range(N-1, -1, -1):
            if i<N-1 and ratings[i]>ratings[i+1]:
                right += 1
            else:
                right = 1
            res += max(left[i], right)
        return res