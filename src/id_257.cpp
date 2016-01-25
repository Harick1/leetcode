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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        string s_val = intToString(root->val);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(s_val);
            return res;
        };
        vector<string> right, left;
        right = binaryTreePaths(root->right);
        left = binaryTreePaths(root->left);
        for (int i(0); i < left.size(); i++) 
            res.push_back(s_val + "->" + left[i]);
        for (int i(0); i < right.size(); i++)
            res.push_back(s_val + "->" + right[i]);
        return res;
    }
    
    string intToString(int n) {
        stringstream ss;
        string s;
        ss << n;
        ss >> s;
        return s;
    }
};