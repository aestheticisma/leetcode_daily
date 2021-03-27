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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = dummyHead;
        int num = 0;
        while (cur->next) {
            num++;
            cur = cur->next;
        }
        if (k % num == 0) return dummyHead->next;
        k %= num;
        cur->next = dummyHead->next;
        // ListNode *res = new ListNode(0, cur);
        cur = dummyHead;
        int i = 0;
        while (cur->next && i<num-k) {
            cur = cur->next;
            i++;
        }
        ListNode *p = cur->next;
        cur->next = nullptr;
        return p;
    }
};