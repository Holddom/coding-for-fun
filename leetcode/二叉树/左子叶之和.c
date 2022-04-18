/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum = 0;
void find(struct TreeNode* root, int flag)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL && flag == 1)
        sum += root->val;
    if (root->left != NULL)
        find(root->left, 1);
    if (root->right != NULL)
        find(root->right, 0);
}
int sumOfLeftLeaves(struct TreeNode* root) {
    int flag = 0;   //表示为右子叶
    sum = 0;
    find(root, flag);
    return sum;

}
