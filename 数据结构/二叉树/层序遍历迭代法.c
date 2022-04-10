/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Return an array of arrays of size *returnSize.
  * The sizes of the arrays are returned as *returnColumnSizes array.
  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
  */


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;  //����������������
    if (root == NULL)
        return NULL;
    int** ans = (int**)malloc(sizeof(int*) * 2001);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2001);//���������ÿһ��Ľ����� ���Կ���
    struct TreeNode* Queue[2001];                       //һ����ά���飬�����ÿһ�������еĽ�����
    int front = 0;                                        //����һ��malloc�Ķ�ά���飬�����
    int rear = 0;                                         //ÿһ�����ֵ
    struct TreeNode* cur;
    Queue[rear++] = root;
    while (front != rear)
    {
        int count = 0;   //ÿһ����ĸ���
        int last = rear; //��־��ÿһ��Ľ���
        ans[*returnSize] = (int*)malloc(sizeof(int) * (last - front));
        while (front < last)
        {
            cur = Queue[front++];
            ans[*returnSize][count++] = cur->val;
            if (cur->left != NULL) { Queue[rear++] = cur->left; }
            if (cur->right != NULL) { Queue[rear++] = cur->right; }
        }
        (*returnColumnSizes)[*returnSize] = count;
        (*returnSize)++;
    }
    return ans;
}
