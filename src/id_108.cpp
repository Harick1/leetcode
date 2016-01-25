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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return util(num, 0, num.size());
    }
    
    TreeNode *util(const vector<int>& num, int start, int end) {
        if (start >= end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = util(num, start, mid);
        root->right = util(num, mid+1, end);
        return root;
    }
};