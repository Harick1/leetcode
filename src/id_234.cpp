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
        if (head == NULL) return true;
        if (head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next;
        ListNode* p = slow->next;
        ListNode* q = slow;
        while(p != NULL) {
            ListNode* tmp = p->next;
            p->next = q;
            q = p;
            p = tmp;
        }
        slow->next = NULL;
        while (q) {
            if (q->val != head->val) return false;
            q = q->next;
            head = head->next;
        }
        return true;
    }
};