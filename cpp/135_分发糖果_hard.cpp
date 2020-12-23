// 法一：
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

//法二：
class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        vector<int> left(N);
        for(int i=0; i<N; i++)
            if(i>0 && ratings[i]>ratings[i-1])
                left[i] = left[i-1] + 1;
            else
                left[i] = 1;
        int right = 0, res = 0;
        for(int i=N-1; i>=0; i--){
            if(i<N-1 && ratings[i]>ratings[i+1])
                right++;
            else 
                right = 1;
            res += max(left[i], right);
        }
        return res;
    }
};