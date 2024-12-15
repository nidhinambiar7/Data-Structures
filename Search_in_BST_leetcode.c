/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Base case: if root is NULL or the value matches the current node
    if (root == NULL || root->val == val) {
        return root;
    }
    
    // If the value to search is smaller, go to the left subtree
    if (val < root->val) {
        return searchBST(root->left, val);
    }
    
    // If the value to search is greater, go to the right subtree
    return searchBST(root->right, val);
}
