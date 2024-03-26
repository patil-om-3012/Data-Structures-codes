//Leetcode 687:Longest Univalue path
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
int ans;
    int solve(TreeNode* root,int parent){
        if(!root){
            return 0;
        }

        int left = solve(root->left,root->val);
        int right = solve(root->right,root->val);

        ans = max(ans,left+right);

        return root->val == parent?max(left,right)+1:0;
    }

    int longestUnivaluePath(TreeNode* root) {
        solve(root,-1);
        return ans;
    }
};
