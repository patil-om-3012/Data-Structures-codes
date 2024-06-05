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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int x = q.size();
            long long cur = 0;
            while(x--){
                TreeNode* temp = q.front();
                q.pop();

                cur += static_cast<long long>(temp->val);

                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
            pq.push(cur);
        }

        k--;
        while(!pq.empty() && k--){
            pq.pop();
        }

        return pq.empty()?-1:pq.top();
    }
};