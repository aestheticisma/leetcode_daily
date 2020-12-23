class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        int res = 1;
        int ins = 1;
        int des = 0;
        int pre = 1;
        for(int i=1; i<N; i++){
            if(ratings[i]>=ratings[i-1]){
                des = 0;
                ins = ratings[i] == ratings[i-1] ? 1 : pre+1;
                res += ins;
                pre = ins;
            }
            else{
                des++;
                if(des==ins)
                    des++;
                res += des;
                pre = 1;
            }
        }
        return res;
    }
};