class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
            return 0;
        stack<int> data;
        // stack.push();
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int x = data.top();
                data.pop();
                int y = data.top();
                data.pop();
                if (tokens[i] == "+")
                    data.push(x+y);
                if (tokens[i] == "-")
                    data.push(y-x);
                if (tokens[i] == "*")
                    data.push(x*y);
                if (tokens[i] == "/")
                    data.push(y/x);
            }
            else 
                data.push(atoi(tokens[i].c_str()));
        }
        return data.top();

    }
};