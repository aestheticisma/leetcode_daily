class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        N = len(coordinates)
        if N<3: return True;
        x0, y0 = coordinates[0][0], coordinates[0][1];
        for i in range(1, N):
            coordinates[i][0] -= x0
            coordinates[i][1] -= y0
        A, B = -coordinates[1][1], coordinates[1][0]
        for i in range(2, N):
            if A*coordinates[i][0]+B*coordinates[i][1]!=0:
                return False
        return True
