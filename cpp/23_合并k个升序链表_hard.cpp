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
    ListNode *merge2Lists(ListNode *a, ListNode *b) {
        if (!a || !b) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val <= bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else if (aPtr->val > bPtr->val) {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = aPtr ? aPtr : bPtr;
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for (int i=0; i<lists.size(); i++) {
            ans = merge2Lists(ans, lists[i]);
        }
        return ans;
    }
};