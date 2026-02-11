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
    bool isCompleteTree(TreeNode* root) {
        vector<int> bfs;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();q.pop();
            bfs.push_back(curr?(curr->val):-1);
            if(curr!=NULL) q.push(curr->left);
            if(curr!=NULL) q.push(curr->right);
        }

        bool found = false;
        for(auto k : bfs){
            if(k==-1) found=true;
            if(found && k!=-1) return false;
        }

        return true;
    }
};