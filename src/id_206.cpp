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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* p = head->next;
        ListNode* q = head;
        while (p != NULL) {
            ListNode* tmp = p->next;
            p->next = q;
            q = p;
            p = tmp;
        }
        head->next = NULL;
        return q;
    }
};