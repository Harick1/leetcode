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
    ListNode *insertionSortList(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *i = head->next, *i_pre = head;
        ListNode *h, *h_pre;
        while (i) {
            h = h_pre = head;
            while (h != i && h->val < i->val) {
                h_pre = h;
                h = h->next;
            }
            if (h != i) {
                i_pre->next = i->next;
                i->next = h;
                if (h == head)
                    head = i;
                else
                    h_pre->next = i;
                i = i_pre->next;
            } else {
                i_pre = i;
                i = i->next;
            }
         }
         return head;
    }
};