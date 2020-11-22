// 法一：横向扫描

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string pre = strs[0];
        for(int i=1; i<strs.size();i++){
            pre = LCS(pre, strs[i]);
            if (pre.length()==0)
                break;
        }
        return pre;
    }
    string LCS(string str1, string str2){
        int minLen = min(str1.length(), str2.length());
        int index = 0;
        for(int i=0; i<minLen; i++){
            if(str1[i]==str2[i])
                index++;
            else break;
        }
        return str1.substr(0, index);
    }
};

// 法二：分治
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())
            return "";
        return divide_strs(strs, 0, strs.size()-1);
    }
    string divide_strs(vector<string> &strs, int start, int end){
        if(start==end)
            return strs[start];
        int mid = (start+end)/2;
        string preLeft = divide_strs(strs, start, mid);
        string preRight = divide_strs(strs, mid+1, end);
        int index = 0;
        int minLen = min(preLeft.length(), preRight.length());
        for(int i=0; i<minLen; i++){
            if(preLeft[i]!=preRight[i])
                break;
            index++;
        }
        return preLeft.substr(0, index);
    }
};

// 法三：二分法 根据公共前缀的长度进行二分
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())
            return "";
        int minLen = strs[0].length();
        for(int i=1; i<strs.size(); i++)
            if(strs[i].length() < minLen)
                minLen = strs[i].length();
        int low = 0, high = minLen;
        while(low <= high){
            int mid = (low+high)/2;
            if(isPrefix(strs, mid))
                low = mid+1;
            else
                high = mid-1;
        }
        int ans = low-1;
        return strs[0].substr(0, ans);
    }
    bool isPrefix(vector<string> &strs, int length){
        string str0 = strs[0].substr(0, length);
        for(int i=1; i<strs.size(); i++){
            string stri = strs[i];
            for(int j=0; j<length; j++){
                if(str0[j]!=stri[j])
                    return false;
            }
        }
        return true;
    }
};