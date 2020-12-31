class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        if(!N)
            return 0;
        for(int i=0; i<N; i++){
            if(n == 0)
                return true;
            if(flowerbed[i] == 0){
                if((i>0 && flowerbed[i-1] == 1) || (i+1<N && flowerbed[i+1] == 1))
                    continue;
                flowerbed[i] = 1;
                n--;
            }
        }
        return n==0;
    }
};