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
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int sum, int target){
        if(!root){
            return;
        }

        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(sum+root->val==target) ans.push_back(temp);
        }


        dfs(root->left,sum+root->val,target);
        dfs(root->right,sum+root->val,target);

        temp.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,0,targetSum);
        return ans;
    }
};