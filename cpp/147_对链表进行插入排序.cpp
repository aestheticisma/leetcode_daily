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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* lastOrder = head;
        ListNode* current = head->next;
        while(current!=nullptr)
        {
            if (current->val >= lastOrder->val)
                lastOrder = lastOrder->next;
            else
            {
                ListNode* pre=dummyHead;
                while(pre->next->val <= current->val)
                    pre = pre->next;
                lastOrder->next = current->next;
                current->next = pre->next;
                pre->next = current;
            }
            current = lastOrder->next;
        }
        return dummyHead->next;
    }
};