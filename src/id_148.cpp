/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *findMiddle(ListNode *head) {
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *res = new ListNode(0);
        ListNode *tail = res;
        while(head1 != NULL && head2 != NULL) {
            if(head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        if(head1 != NULL) {
            tail->next = head1;
        } else {
            tail->next = head2;
        }
        return res->next;
    }

public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *middle = findMiddle(head);
        ListNode *right = sortList(middle->next);
        middle->next = NULL;
        ListNode *left = sortList(head);
        return merge(left, right);
    }
};