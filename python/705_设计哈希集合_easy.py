class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.base = 769
        self.data = [[] for i in range(self.base)]
    
    def calHash(self, x):
        return x % self.base

    def add(self, key: int) -> None:
        h = self.calHash(key)
        for i in range(len(self.data[h])):
            if self.data[h][i] == key:
                return
        self.data[h].append(key)

    def remove(self, key: int) -> None:
        h = self.calHash(key)
        for i in range(len(self.data[h])):
            if self.data[h][i] == key:
                self.data[h].remove(key)
                return

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        h = self.calHash(key)
        for i in range(len(self.data[h])):
            if self.data[h][i] == key:
                return True
        return False


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)