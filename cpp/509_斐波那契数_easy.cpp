class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        int f0 = 0, f1 = 1;
        for(int i=2; i<=n; i++){
            int tmp = f1;
            f1 = f0 + f1;
            f0 = tmp;
        }
        return f1;
    }
};