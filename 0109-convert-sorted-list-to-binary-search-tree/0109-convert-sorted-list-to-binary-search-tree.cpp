/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
ListNode* headPtr;

    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }

    TreeNode* buildTree(int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;

        TreeNode* leftChild = buildTree(start, mid - 1);

        TreeNode* root = new TreeNode(headPtr->val);
        root->left = leftChild;

        headPtr = headPtr->next;

        root->right = buildTree(mid + 1, end);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        headPtr = head;
        int len = getLength(head);
        return buildTree(0, len - 1);
        
    }
};