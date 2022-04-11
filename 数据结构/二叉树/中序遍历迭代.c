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
        while (node != NULL)  //��һֱ������������ֱ��Ϊ��
        {
            stack[top++] = node;
            node = node->left;
        }
        node = stack[--top];                //��������ķ���Ҫ���ڵڶ���ѭ������������ΪnodeΪ�գ���ջһ��Ԫ�ؽ��з���һ����
        ans[(*returnSize)++] = node->val;   //����Ҷ���丸�ڵ㣨����㣩��Ȼ������������ı���
        node = node->right;
    }
    return ans;
}
