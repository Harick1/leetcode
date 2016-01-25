/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return util(head, NULL);
    }
    
    TreeNode *util(ListNode *head, ListNode *end) {
        if (head == end)
            return NULL;
        ListNode *fast, *mid;
        fast = mid = head;
        while (fast->next != end && fast->next->next != end) {
            fast = fast->next->next;
            mid = mid->next;
        }
        TreeNode *root = new TreeNode(mid->val);
        root->left = util(head, mid);
        root->right = util(mid->next, end);
        return root;
    }
};