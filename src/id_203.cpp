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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode* p_head = new ListNode(0);
        p_head->next = head;
        ListNode* p = p_head;
        while (p->next) {
            if (p->next->val == val) {
                if (p->next->next == NULL) {
                    p->next = NULL;
                } else {
                    ListNode* tmp = p->next;
                    p->next = tmp->next;
                    delete tmp;
                }
            } else {
                p = p->next;
            }
        }
        head = p_head->next;
        delete p_head;
        return head;
    }
};