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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL || l2 == NULL)
		return NULL;
    	ListNode *res = new ListNode(0), *t = new ListNode(0);
    	int a(l1->val), b(l2->val);
    	l1 = l1->next;
    	l2 = l2->next;
    	int sum = a + b;
    	int flg = sum / 10;
    	res->val = sum % 10;
    	t = res;
    	while (l1 != NULL || l2 != NULL) {
    		a = l1 == NULL ? 0 : l1->val;
    		b = l2 == NULL ? 0 : l2->val;
    		sum = a + b + flg;
    		flg = sum / 10;
    		ListNode *tmp = new ListNode(0);
    		tmp->val = sum % 10;
    		t->next = tmp;
    		t = tmp;
    		if (l1 != NULL)
    			l1 = l1->next;
    		if (l2 != NULL)
    			l2 = l2->next;
    	}
    	if (flg) {
    		ListNode *tmp = new ListNode(0);
    		tmp->val = 1;
    		t->next = tmp;
    	}
    	return res;
    }
};