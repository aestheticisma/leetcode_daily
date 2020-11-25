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
// 法1: 栈
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *current = dummyHead;
        stack<ListNode*> pos;
        while(current!=nullptr){
            pos.push(current);
            current = current->next;
        }
        for(int i=0; i<n; i++)
            pos.pop();
        current = pos.top();
        current->next = current->next->next;
        ListNode *dummy = dummyHead->next;
        delete dummyHead;
        return dummy;
    }
};