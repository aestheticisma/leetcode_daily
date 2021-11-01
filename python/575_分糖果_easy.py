class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return len(candyType) // 2 if len(set(candyType)) >= (len(candyType) // 2) else len(set(candyType))