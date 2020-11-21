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

//原本的链表插入排序就不写了，时间复杂度O(n^2)较高不适合本题
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return divideList(head, nullptr);
    }
    ListNode* divideList(ListNode* head, ListNode* tail)
    {
        if(head==nullptr)
            return head;
        //注意判断链表只有一个元素的判断方式
        if(head->next==tail)
        {
            head->next=nullptr;
            return head;
        }
        ListNode* slow=head, *fast=head;
        while(fast!=tail)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast!=tail)
                fast = fast->next;
        }
        ListNode* mid = slow;
        //divideList函数左闭右开，因此两边都是mid.
        return merge(divideList(head, mid), divideList(mid, tail));
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};