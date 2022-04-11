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
    while (top > 0 || node != NULL)     //���������Ϊ���ӣ���������Ҫһ��preָ������ס���ڵ�
    {
        while (node != NULL)
        {
            stack[top++] = node;
            node = node->left;
        }                           //�ڶ���ѭ��һ��
        node = stack[--top];
        if (node->right == NULL || node->right == pre)//ע�������ֿ��ܣ�������Һ�������Է���
        {                                               //��������preҪ��ס���node����Ϊ���node���ܻ��ٴα����������丸�ڵ������У�
            ans[(*returnSize)++] = node->val;           //nodeҪ�ÿգ���Ϊ���ǲ����ٴη����������ҽ����
            pre = node;
            node = NULL;
        }
        else                                            //���������������if������
        {                                               //��ô�ͷ���������
            stack[top++] = node;
            node = node->right;
        }
    }
    return ans;
}
