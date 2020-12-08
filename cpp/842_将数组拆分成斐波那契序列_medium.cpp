
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> list;
        isSucceed(list, S, S.length(), 0, 0, 0);
        return list;
    }
    bool isSucceed(vector<int> &list, string &S, int length, int index, long long sum, int pre){
        if(index == length)
            return list.size()>=3;
        long long current = 0;
        for(int i=index; i<length; i++){
            if(i>index && S[index]=='0')
                break;
            current = current*10 + (S[i]-'0');
            if(current>INT_MAX)
                break;
            if(list.size()>=2)
                if(current<sum)
                    continue;
                else if(current>sum)
                    break;
            list.push_back(current);
            if(isSucceed(list, S, length, i+1, pre+current, current))
                return true;
            list.pop_back();
        }
        return false;
    }
};