class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1;
        int high = pow(10, 9);
        while(low <= high){
            int mid = (low+high)/2;
            if(possible(piles, mid, H))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    bool possible(vector<int> &piles, int &k, int &H){
        int times = 0;
        for(int pile : piles)
            times += (pile-1) / k + 1;
        return times <= H;
    }
};