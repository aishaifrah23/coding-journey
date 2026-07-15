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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        calculateHeight(root, maxDiameter);
        return maxDiameter;
    }

private:
    int calculateHeight(TreeNode* node, int& maxDiameter) {
        if (!node) return 0;

        int leftHeight = calculateHeight(node->left, maxDiameter);
        int rightHeight = calculateHeight(node->right, maxDiameter);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
};