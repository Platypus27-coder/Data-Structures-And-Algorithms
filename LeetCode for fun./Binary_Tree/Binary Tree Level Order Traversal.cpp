/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;

    void level(TreeNode *root) {
        if (root == nullptr) return;
        queue<TreeNode *> T;
        T.push(root);
        while(!T.empty()) {
            int s = T.size();
            vector<int> v;
            for (int i = 0; i < s; i++) {
                TreeNode *node = T.front();
                T.pop();
                if (node->left != nullptr) T.push(node->left);
                if (node->right != nullptr) T.push(node->right);
                v.push_back(node->val);
            }   
            res.push_back(v);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        level(root);
        return res;
    }
};
