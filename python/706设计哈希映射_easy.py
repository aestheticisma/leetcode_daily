class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.base = 769
        self.data = [[] for i in range(self.base)]
    

    def calHash(self, key):
        return key % self.base


    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        h = self.calHash(key)
        for i in range(len(self.data[h])):
            if self.data[h][i][0] == key:
                self.data[h][i][1] = value
                return
        self.data[h].append([key, value])


    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        h = self.calHash(key)
        for i in range(len(self.data[h])):
            if self.data[h][i][0] == key:
                return self.data[h][i][1]
        return -1

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        h = self.calHash(key)
        for i in range(len(self.data[h])):
            if self.data[h][i][0] == key:
                self.data[h].remove(self.data[h][i])
                return


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)