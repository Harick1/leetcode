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
    void flatten(TreeNode *root) {
        root = flatten_plus(root);
    }
    
    TreeNode* flatten_plus(TreeNode *root) {
        if (root == NULL || root->left == NULL && root->right == NULL)
            return root;
        TreeNode *tmp_right = flatten_plus(root->right);
        TreeNode *tmp_left = flatten_plus(root->left);
        TreeNode *head = root;
        root->right = tmp_left;
        root->left = NULL;
        while (head->right != NULL)
            head = head->right;
        head->right = tmp_right;
        return root;
    }
};