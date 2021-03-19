class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.data = [big, medium, small]

    def addCar(self, carType: int) -> bool:
        if self.data[carType-1]:
            self.data[carType-1] -= 1
        else:
            return False
        return True



# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)