class ParkingSystem {
    int data[3];
public:
    ParkingSystem(int big, int medium, int small) {
        data[0] = big;
        data[1] = medium;
        data[2] = small;
    }
    
    bool addCar(int carType) {
        if (data[carType-1] > 0)
            data[carType-1]--;
        else
            return false;
        return true;   
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */