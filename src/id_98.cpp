/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTPlus(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
private:
    bool isValidBSTPlus(TreeNode* root, long long min, long long max) {
        if (root == NULL) return true;
        if (root->val <= min || root->val >= max) return false;
        long long l_max = root->val;
        long long r_min = root->val;
        return isValidBSTPlus(root->left, min, l_max) && isValidBSTPlus(root->right, r_min, max);
    }
};