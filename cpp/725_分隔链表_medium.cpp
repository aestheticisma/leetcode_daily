/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *p = head;
        int n = 0;
        for(; p!=nullptr; ++n) p = p->next;
        p = head;
        int sub = n / k;
        int mod = n % k;
        vector<int> data(k, sub);
        for (int i=0; i<mod; i++) data[i]++;
        vector<ListNode*> ans;
        ListNode *temp;
        for (auto d : data) {
            if (d == 0) {
                //ListNode *res = new ListNode();
                ans.push_back(nullptr);
            }
            else{
                ans.push_back(p);
                for (int i=1; i<d; i++) p = p->next;
                temp = p->next;
                p->next = nullptr;
                p = temp;
            }
        }
        return ans;
    }
};