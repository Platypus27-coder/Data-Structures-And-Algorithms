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
    int result = 0;

    void find(TreeNode *root, int tmp) {
        if (root == nullptr) {
            return;
        }
        tmp = tmp * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            result += tmp;
        }
        find(root->left, tmp);
        find(root->right, tmp);
    }

    int sumNumbers(TreeNode* root) {
        find(root, 0);
        return result;
    }
};
