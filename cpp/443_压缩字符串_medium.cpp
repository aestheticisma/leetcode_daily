class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0, left = 0;
        for (int read = 0; read < n; read++) {
            if (read == n-1 || chars[read] != chars[read+1]) {
                chars[write++] = chars[read];
                int length = read - left + 1;
                if (length > 1) {
                    int tmp = write;
                    while (length > 0) {
                        chars[write++] = '0' + length%10;
                        length /= 10;
                    }
                    reverse(&chars[tmp], &chars[write]);
                }
                left = read + 1;
            }
        }
        return write;
    }
};