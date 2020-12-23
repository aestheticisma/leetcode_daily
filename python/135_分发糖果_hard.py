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