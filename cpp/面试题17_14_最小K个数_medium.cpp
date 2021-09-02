// 优先队列
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int n = arr.size();
        if (k == 0) return {};
        vector<int> ans(k, 0);
        priority_queue<int> Q;
        for (int i=0; i<k; i++)
            Q.push(arr[i]);
        for (int i=k; i<n; i++) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i=k; i>0; i--) {
            ans[i-1] = Q.top();
            Q.pop();
        }
        return ans;
    }
};

// 快排
class Solution {
private:
    vector<int> res;
    void Qsort(vector<int> &arr, int k, int left, int right) {
        if (left > right) return;
        int i = left, j = right;
        while (i < j) {
            for (; i<j && arr[j]>=arr[left]; j--);
            for (; i<j && arr[i]<=arr[left]; i++);
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[left]);
        if (i == k) 
            res.assign(arr.begin(), arr.begin()+k);
        else if (i > k)
            Qsort(arr, k, left, right-1);
        else
            Qsort(arr, k, i+1, right);
    }

public:
    vector<int> smallestK(vector<int>& arr, int k) {
        Qsort(arr, k, 0, arr.size()-1);
        return res;
    }
};