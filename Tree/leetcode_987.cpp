//Leecode_987:  Vertical Order Traversal of a Binary Tree
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        queue<pair<TreeNode*, pair<int, int>>> q; // node, <row, column>
        unordered_map<int, map<int, multiset<int>>> hashMap; // column -> {row -> values}
        int nodes = 0;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> p = q.front();
            q.pop();
            nodes++;
            hashMap[p.second.second][p.second.first].insert(p.first->val);

            if (p.first->left) {
                q.push({p.first->left, {p.second.first + 1, p.second.second - 1}});
            }

            if (p.first->right) {
                q.push({p.first->right, {p.second.first + 1, p.second.second + 1}});
            }
        }

        vector<int> keys;
        for (const auto& pair : hashMap) {
            keys.push_back(pair.first);
        }

        sort(keys.begin(), keys.end());

        vector<vector<int>> ans;

        for (auto it : keys) {
            vector<int> levelValues;
            for (const auto& rowPair : hashMap[it]) {
                for (int val : rowPair.second) {
                    levelValues.push_back(val);
                }
            }
            ans.push_back(levelValues);
        }

        return ans;
    }
};
