/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, int> mapG;
        for(int g:G) mapG[g] = 1;
        ListNode *p = head;
        int ans = 0;
        while(p->next){
            if(mapG.find(p->val) != mapG.end() && mapG.find(p->next->val) == mapG.end())
                ans++;
            p = p->next;
        }
        if(mapG.find(p->val) != mapG.end())
            ans++;
        return ans;
    }
};