class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(n1 == 0) return 0;
        int s1cnt = 0, s2cnt=0, index=0;
        int ans = 0;
        unordered_map<int, pair<int, int>> hash_map;
        int pre_s1cnt;
        int pre_s2cnt;
        int inloop_s2;
        int inloop_s1;
        while(true)
        {
            s1cnt++;
            for(int i=0; i<s1.length(); i++)
            {
                if (s1[i]==s2[index])
                {
                    index++;
                    if(index==s2.length())
                        {
                            index=0;
                            s2cnt++;
                        }
                }
            }
            if(s1cnt==n1)
                return s2cnt/n2;
            if(hash_map.find(index) != hash_map.end())
            {
                pre_s1cnt = hash_map[index].first;
                pre_s2cnt = hash_map[index].second;
                inloop_s1 = s1cnt-pre_s1cnt;
                inloop_s2 = s2cnt-pre_s2cnt;
                break;
            }
            else hash_map[index]={s1cnt, s2cnt};
        }
        ans = pre_s2cnt + (n1-pre_s1cnt)/inloop_s1 * inloop_s2;
        // 暴力匹配剩余字符串
        int rest_cnt =  (n1-pre_s1cnt) % inloop_s1;
        for(int i=0;i<rest_cnt;i++)
            for(int j=0;j<s1.length();j++)
            {
                if(s1[j]==s2[index])
                {
                    index++;
                    if(index==s2.length())
                    {
                        index = 0;
                        ans++;
                    }
                }
            }
        return ans/n2;

    }
};