class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1)
            return false;
        vector<char> stack;
        unordered_map<char, char> strMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (char ch : s){
            if (strMap.count(ch) != 0){
                if (!stack.size() || stack[stack.size()-1] != strMap[ch])
                    return false;
                stack.pop_back();
            }
            else
                stack.push_back(ch);
        }
        return stack.size() == 0 ? true : false;
    }
};