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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* ans = malloc(sizeof(int) * 2000);
    if (root == NULL)
        return ans;
    struct TreeNode* stack[2000];
    int top = 0;
    struct TreeNode* node = root;
    struct TreeNode* pre = NULL;
    while (top > 0 || node != NULL)     //后序遍历较为复杂，它额外需要一个pre指针来记住父节点
    {
        while (node != NULL)
        {
            stack[top++] = node;
            node = node->left;
        }                           //第二个循环一样
        node = stack[--top];
        if (node->right == NULL || node->right == pre)//注意有两种可能，如果无右孩子则可以访问
        {                                               //但别忘了pre要记住这个node，因为这个node可能会再次遍历到（从其父节点再向有）
            ans[(*returnSize)++] = node->val;           //node要置空，因为我们不想再次访问它的左右结点了
            pre = node;
            node = NULL;
        }
        else                                            //如果不满足上述的if条件，
        {                                               //那么就访问右子树
            stack[top++] = node;
            node = node->right;
        }
    }
    return ans;
}
