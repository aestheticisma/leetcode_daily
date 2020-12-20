class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<char> flag(26, 0), num(26, 0);
        for(char ch : s)
            num[ch-'a']++;
        string stack;
        for(char ch : s){
            if(!flag[ch-'a']){
                while(!stack.empty() && stack.back()>ch){
                    if(num[stack.back()-'a'] > 0){
                        flag[stack.back()-'a'] = 0;
                        stack.pop_back();
                    }
                    else
                        break;
                }
                stack.push_back(ch);
                flag[ch-'a'] = 1;
            }
            num[ch-'a']--;
        }
        return stack;
    }
};