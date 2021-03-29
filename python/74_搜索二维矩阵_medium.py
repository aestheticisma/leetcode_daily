class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def findx(matrix_row):
            for num in matrix_row:
                if target == num:
                    return True
            return False

        row, col = len(matrix), len(matrix[0])
        top, bottom, mid = 0, row, 0
        while top < bottom:
            mid = (top + bottom) // 2
            if target == matrix[mid][0]:
                return True
            elif target < matrix[mid][0]:
                bottom -= 1
            else:
                if target == matrix[mid][-1]:
                    return True
                elif target < matrix[mid][-1]:
                    return findx(matrix[mid])
                else:
                    top += 1
        return False

