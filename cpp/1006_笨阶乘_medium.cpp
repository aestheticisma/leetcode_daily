class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N);
        N--;
        int index = 0;
        while (N) {
            if (index%4 == 0)
                stk.top() *= N;
            else if (index%4 == 1)
                stk.top() /= N;
            else if (index%4 == 2)
                stk.push(N);
            else
                stk.push(-N);
            index++;
            N--;
        }
        int ans = 0;
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        return ans;

    }
};