/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL)  //ตÝน้
        return NULL;

    if (val < root->val)
        return searchBST(root->left, val);
    if (val > root->val)
        return searchBST(root->right, val);
    return root;
}