/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode* p, struct TreeNode* q)  //µÝ¹é¾ÍÊÇ¼òµ¥
{
    if (p == NULL && q == NULL)return true;
    if (p == NULL || q == NULL)return false;
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    return check(root, root);
}