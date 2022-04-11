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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* ans = malloc(sizeof(int) * 2000);
    if (root == NULL)
        return ans;
    struct TreeNode* stack[2000];
    int top = 0;
    struct TreeNode* node = root;

    while (top > 0 || node != NULL)
    {
        while (node != NULL)  //先一直遍历左子树，直到为空
        {
            stack[top++] = node;
            node = node->left;
        }
        node = stack[--top];                //中序遍历的访问要放在第二个循环的条件后，因为node为空，出栈一个元素进行访问一定是
        ans[(*returnSize)++] = node->val;   //左子叶或其父节点（根结点），然后进行右子树的遍历
        node = node->right;
    }
    return ans;
}
