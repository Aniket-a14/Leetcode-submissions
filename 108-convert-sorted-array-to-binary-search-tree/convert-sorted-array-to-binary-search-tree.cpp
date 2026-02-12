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
    TreeNode* bst(int low,int high,vector<int>& nums){
        if(low>high) return NULL;

        int mid=low+(high-low)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left= bst(low,mid-1,nums);
        temp->right = bst(mid+1,high,nums);

        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;

        return bst(low,high,nums);
    }
};