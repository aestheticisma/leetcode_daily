class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if not flowerbed:
            return 0
        for i in range(len(flowerbed)):
            if n == 0:
                return True
            if flowerbed[i] == 0:
                if (i > 0 and flowerbed[i-1] == 1) or (i+1 < len(flowerbed) and flowerbed[i+1] == 1):
                    continue
                flowerbed[i] = 1
                n -= 1
        return n == 0