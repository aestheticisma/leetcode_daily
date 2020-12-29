//直接使用c++中的大顶堆: priority_queue 也就是优先队列

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> maxHeap;
        for(int stone : stones)
            maxHeap.push(stone);
        while(maxHeap.size()>1){
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if(x!=y)
                maxHeap.push(abs(x-y));
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
        
    }
};