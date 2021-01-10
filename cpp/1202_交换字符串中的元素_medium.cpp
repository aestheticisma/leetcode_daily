class Solution {
public:
    static const int num = 1e5 + 5;
    int p[num];
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int N = s.length();
        for(int i=0; i<N; i++)
            p[i] = i;
        for(auto pair : pairs){
            int pair1 = pair[0];
            int pair2 = pair[1];
            p[find_union(pair2)] = find_union(pair1);
        }
        unordered_map<int, vector<int>> d;
        string ans = s;
        for(int i=0; i<N; i++)
            d[find_union(i)].push_back(i);
        for(auto iter=d.begin(); iter!=d.end(); iter++){
            auto q = iter->second;
            string t;
            for(auto i : q)
                t+=s[i];
            sort(t.begin(), t.end());
            sort(q.begin(), q.end());
            int index = 0;
            for(auto i : q)
                ans[i] = t[index++];
        }
        return ans;
    }

    int find_union(int x){
        if(x!=p[x])
            p[x] = find_union(p[x]);
        return p[x];
    }
};