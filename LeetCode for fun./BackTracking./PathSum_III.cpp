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
    long long currSum = 0;
    unordered_map<long long, int> mp;
    int res = 0;

    void dfs(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return;
        }
        currSum += root->val;
        if (mp[currSum - targetSum]) {
            res += mp[currSum - targetSum];
        }
        mp[currSum]++;
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        mp[currSum]--;
        currSum -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        dfs(root, targetSum);
        return res;
    }
};
