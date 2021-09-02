class Solution:
    def smallestK(self, arr: List[int], k: int) -> List[int]:
        def Qsort(left, right):
            if left > right:
                return
            i, j = left, right
            while i < j:
                while i < j and arr[j] >= arr[left]:
                    j -= 1
                while i < j and arr[i] <= arr[left]:
                    i += 1
                arr[i], arr[j] = arr[j], arr[i]
            arr[i], arr[left] = arr[left], arr[i]
            if i == k:
                return
            elif i > k:
                Qsort(left, i-1)
            else:
                Qsort(i+1, right)
        Qsort(0, len(arr)-1)
        return arr[:k]