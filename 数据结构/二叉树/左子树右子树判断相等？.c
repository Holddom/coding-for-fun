/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;
	if (isSymmetric(root->left) && isSymmetric(root->right))
		return true;
	else
		return false;
}