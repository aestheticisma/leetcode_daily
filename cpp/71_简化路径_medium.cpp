class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) return path;
        queue<string> pathList;
        string str;
        for (const char ch : path) {
            if (ch == '/') {
                if (!str.empty()) pathList.push(str);
                str.clear();
                continue;
            }
            str += ch;
        }
        if (!str.empty()) pathList.push(str);
        stack<string> stk;
        while (!pathList.empty()) {
            if (pathList.front() == ".") {
                pathList.pop();
                continue;
            }
            else if (!stk.empty() && pathList.front() == "..")
                stk.pop();
            else {
                if (pathList.front() != "..")
                    stk.push(pathList.front());
            }
            pathList.pop();
        }
        vector<string> tmp(stk.size());
        int n = stk.size() - 1;
        while (!stk.empty()) {
            tmp[n--] = stk.top();
            stk.pop();
        }
        string ans = "/";
        for (int i = 0; i < tmp.size(); ++i) {
            ans += tmp[i];
            ans += "/";
        }
        return ans.length() == 1 ? ans : ans.substr(0, ans.length()-1);
    }
};