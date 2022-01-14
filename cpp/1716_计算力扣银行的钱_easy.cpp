class Solution {
public:
    int totalMoney(int n) {
        int weekNum = n / 7, dayNum = n % 7;
        int firstWeekMoney = (1 + 7) * 7 / 2;
        int lastWeekMoney = firstWeekMoney + 7 * (weekNum - 1);
        int weekMoney = (firstWeekMoney + lastWeekMoney) * weekNum / 2;
        int firstDayMoney = 1 + weekNum;
        int lastDayMoney = firstDayMoney + dayNum - 1;
        int dayMoney = (firstDayMoney + lastDayMoney) * dayNum / 2;
        return weekMoney + dayMoney;
    }
};