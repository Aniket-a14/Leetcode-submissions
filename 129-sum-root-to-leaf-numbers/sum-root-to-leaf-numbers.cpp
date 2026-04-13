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
    string temp = "";
    int ans;
    void dfs(TreeNode* root){
        if(!root) return;

        temp += to_string(root->val);

        if(!root->left && !root->right){
            ans += stoi(temp);
        }

        dfs(root->left);
        dfs(root->right);

        temp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        dfs(root);

        return ans;
    }
};