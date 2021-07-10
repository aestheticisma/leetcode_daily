class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = collections.defaultdict(list)


    def set(self, key: str, value: str, timestamp: int) -> None:
        self.data[key].append((timestamp, value))


    def get(self, key: str, timestamp: int) -> str:
        tempList = self.data[key]
        left, right = 0, len(tempList)
        while left < right:
            mid = left + (right - left) // 2
            if tempList[mid][0] <= timestamp:
                left = mid + 1
            else:
                right = mid
        if left > 0:
            return tempList[left-1][1]
        else:
            return ""



# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)