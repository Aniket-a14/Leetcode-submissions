class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, long long sum, int target) {
        if (!root) return;

        sum += root->val;

        if (sum == target) ans++;

        dfs(root->left, sum, target);
        dfs(root->right, sum, target);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        dfs(root, 0, targetSum); 
        pathSum(root->left, targetSum); 
        pathSum(root->right, targetSum); 

        return ans;
    }
};