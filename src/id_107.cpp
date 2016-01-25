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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelOrderBottomPlus(res, root, 0);
        vector<vector<int>> final_res(res.rbegin(), res.rend());
        return final_res;
    }

private:
    void levelOrderBottomPlus(vector<vector<int>>& res, TreeNode* root, int level) {
        if (root == NULL) return;
        if (res.size() == level) {
            vector<int> tmp;
            res.push_back(tmp);
        }
        res[level].push_back(root->val);
        levelOrderBottomPlus(res, root->left, level+1);
        levelOrderBottomPlus(res, root->right, level+1);
    }
};