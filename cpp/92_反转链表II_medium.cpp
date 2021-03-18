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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head==nullptr || left >= right)
            return head;
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *p = head;
        ListNode *begin = dummyHead;
        stack<ListNode*> stk;
        int pos = 1;
        while (p!=nullptr) {
            if (pos < left)
                begin = p;
            else if (pos>=left && pos<=right)
                stk.push(p);
            else 
                break;
            pos++;
            p = p->next;
        }
        // cout<<stk.top()->val;
        while (!stk.empty()) {
            begin->next = stk.top();
            stk.pop();
            begin = begin->next;
        }        
        if (begin!=nullptr)
            begin->next = p;
        return dummyHead->next;
    }
};