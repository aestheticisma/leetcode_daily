// 法1:
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
    bool isPalindrome(ListNode* head) {
        if(!head || head->next==nullptr)
            return true;
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *first = dummyHead->next, *second = dummyHead->next;
        int num1 = 0, num2 = 0;
        while(first->next!=nullptr){
            first = first->next;
            num1++;
            if(first->next!=nullptr){
                first = first->next;
                second = second->next;
                num2++;
            }
        }
        int step = num1>num2 ? num2+1 : num2;
        first->next = dummyHead->next;
        int a1[step], a2[step];
        num1 = 0, num2 = 0;
        int count = step;
        while(count){
            first = first->next;
            a1[num1++] = first->val;
            second = second->next;
            a2[num2++] = second->val;
            count--;
        } 
        for(int i = step-1; i>=0; i--)
            if(a1[i] != a2[step-i-1])
                return false;
        return true;
    }
};


// 法2:
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
    bool isPalindrome(ListNode* head) {
        bool res = true;
        ListNode *tail = head;
        dfs(head, tail, res);
        return res;
    }
    void dfs(ListNode* &head, ListNode* &tail, bool &res){
        if(!tail)
            return;
        dfs(head, tail->next, res);
        if(head->val != tail->val)
            res = false;
        head = head->next;
    }
};