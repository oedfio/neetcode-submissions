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
    pair<int, int> computeDiameter(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        auto [l_depth, l_diameter] = computeDiameter(root->left);
        auto [r_depth, r_diameter] = computeDiameter(root->right);
        int cur_diameter = l_depth + r_depth;
        int cur_depth = 0;
        if (root->left != nullptr) {
            cur_diameter++;
            cur_depth = l_depth + 1;
        }
        if (root->right != nullptr) {
            cur_diameter++;
            cur_depth = max(cur_depth, r_depth + 1);
        }
        cout << "Node: " << root->val << "\t" << cur_depth << "\t" << cur_diameter << endl; 
        return {cur_depth, max(l_diameter, max(r_diameter, cur_diameter))};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        auto [dep, dim] = computeDiameter(root);
        return max(dep, dim);
    }
};
