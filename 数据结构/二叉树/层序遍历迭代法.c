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
    *returnSize = 0;  //这个变量是树的深度
    if (root == NULL)
        return NULL;
    int** ans = (int**)malloc(sizeof(int*) * 2001);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2001);//这个是树的每一层的结点个数 可以看成
    struct TreeNode* Queue[2001];                       //一个二维数组，存放这每一层所具有的结点个数
    int front = 0;                                        //返回一个malloc的二维数组，存放着
    int rear = 0;                                         //每一层结点的值
    struct TreeNode* cur;
    Queue[rear++] = root;
    while (front != rear)
    {
        int count = 0;   //每一层结点的个数
        int last = rear; //标志着每一层的结束
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
