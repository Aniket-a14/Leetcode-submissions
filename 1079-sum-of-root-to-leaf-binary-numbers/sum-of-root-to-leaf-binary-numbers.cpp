/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;
    string temp = "";
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }

        temp += to_string(root->val);

        if (!root->left && !root->right)
            ans.push_back(temp);

        dfs(root->left);
        dfs(root->right);
        temp.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);

        int sum = 0;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
            sum += stoi(ans[i], NULL, 2);
        }

        return sum;
    }
};