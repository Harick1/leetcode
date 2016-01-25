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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrderPlus(res, root, 0);
        return res;
    }
private:  
    void levelOrderPlus(vector<vector<int>>& res, TreeNode* root, int level) {
        if (root == NULL) return;
        if (res.size() == level) {
            vector<int> tmp;
            res.push_back(tmp);
        }
        res[level].push_back(root->val);
        levelOrderPlus(res, root->left, level+1);
        levelOrderPlus(res, root->right, level+1);
    }
};