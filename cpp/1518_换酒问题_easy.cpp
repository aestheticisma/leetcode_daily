class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles / numExchange) {
            int remain = numBottles % numExchange;
            int change = numBottles / numExchange;
            ans += change;
            numBottles = remain + change;
        }
        return ans;
    }
};