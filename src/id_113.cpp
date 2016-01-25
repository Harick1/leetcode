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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> one_res;
        solve (res, one_res, root, sum);
        return res;
    }
    
    void solve(vector<vector<int> > &res, vector<int> &one_res, TreeNode *root, int sum) {
        if (root == NULL)
            return;
        sum -= root->val;
        if (root->left == NULL && root->right == NULL) {
            if (!sum) {
                one_res.push_back(root->val);
                res.push_back(one_res);
                one_res.erase(one_res.end()-1);
            }
            return;
        }
        one_res.push_back(root->val);
        solve(res, one_res, root->left, sum);
        solve(res, one_res, root->right, sum);
        one_res.erase(one_res.end()-1);
    }
};