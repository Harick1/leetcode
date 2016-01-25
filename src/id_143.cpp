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
    void reorderList(ListNode *head) {
        if (head == NULL)
            return;
        if (head->next == NULL)
            return;
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast->next != NULL) {
            fast = fast->next;
            if (fast->next == NULL)
                break;
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;
        head2 = reverse(head2);
        ListNode *head1 = head;
        while (head1 != NULL && head2 != NULL) {
            ListNode *next = head2->next;
            head2->next = head1->next;
            head1->next = head2;
            head1 = head2->next;
            head2 = next;
        }
    }
    ListNode* reverse (ListNode *head) {
        ListNode *middle, *tail;
        middle = NULL;
        while (head) {
            tail = middle;
            middle = head;
            head = head->next;
            middle->next = tail;
        }
        return middle;
    }
};