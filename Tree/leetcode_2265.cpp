//Leetcode 2265. Count Nodes Equal to Average of Subtree
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
    int ans = 0;

    pair<int,int> func(TreeNode* root)
    {
        if(!root)
        {
            return {0,0};
        }

        pair<int,int> l = func(root->left);
        pair<int,int> r = func(root->right);

        int sum = l.first + r.first + root->val;
        int val = l.second + r.second + 1;

        if(root->val == sum/val)
        {
            ans++;
        }

        return {sum,val};
    }

    int averageOfSubtree(TreeNode* root) {
        func(root);
        return ans;
    }
};
