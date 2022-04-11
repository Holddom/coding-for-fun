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
void reverse(struct TreeNode* root, int* res, int* returnSize)
{
    if (root == NULL)                               //�ݹ��ǰ�к�ֻ��res[(*returnSize)++] = root->val;��˳��ͬ
        return;
    else
    {
        res[(*returnSize)++] = root->val;
        reverse(root->left, res, returnSize);
        reverse(root->right, res, returnSize);
    }
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {


    {
        int* res = (int*)malloc(100 * sizeof(int));
        *returnSize = 0;
        reverse(root, res, returnSize);
        return res;
    }

}
