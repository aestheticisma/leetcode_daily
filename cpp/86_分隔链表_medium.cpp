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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        ListNode *tmp = new ListNode(0);
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *p = dummyHead;
        ListNode *pt = tmp;
        while(p->next != nullptr){
            if(p->next->val < x)
                p = p->next;
            else{
                tmp->next = p->next;
                p->next = p->next->next;
                tmp = tmp->next;
                tmp->next = nullptr;
            }
        }
        p->next = pt->next;
        return dummyHead->next;
        
    }
};