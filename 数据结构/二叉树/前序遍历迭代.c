/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(sizeof(int) * 2000);
    *returnSize = 0;
    if (root == NULL)               
        return NULL;

    struct TreeNode* stack[2000];
    int top = 0;
    struct TreeNode* node = root;
    while (top > 0 || node != NULL)                     //注意循环条件
    {
        while (node != NULL)
        {
            ans[(*returnSize)++] = node->val;       //前序就是直接访问然后向左遍历
            stack[top++] = node;
            node = node->left;
        }                                               //第二个循环结束就出栈访问右子树
        node = stack[--top];
        node = node->right;
    }
    return ans;
}
