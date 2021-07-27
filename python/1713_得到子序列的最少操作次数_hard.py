class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        t = len(target)
        tar = dict()
        for i in range(t):
            tar[target[i]] = i
        data = []
        for a in arr:
            if a in tar:
                data.append(tar[a])
        if not data:
            return t
        n = len(data)
        d = []
        for num in data:
            if not d or num > d[-1]:
                d.append(num)
            else:
                l, r = 0, len(d)-1
                pos = r
                while l <= r:
                    mid = l + (r - l) // 2
                    if d[mid] >= num:
                        pos = mid
                        r = mid - 1
                    else:
                        l = mid + 1
                d[pos] = num
        return t - len(d)