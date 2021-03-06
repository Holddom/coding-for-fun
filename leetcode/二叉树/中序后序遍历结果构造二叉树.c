/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {    //自顶向下递归法
    if (inorderSize < 1)
        return NULL;
    int size = inorderSize; //两个数组大小相等
    int tmp = postorder[postorderSize - 1];
    int i;
    for (i = 0; i < inorderSize; i++)
    {
        if (inorder[i] == tmp)
            break;
    }
    int left_size = i; int right_size = size - i - 1;        //size值的更新
    int* left_in = inorder; int* right_in = inorder + i + 1;  //传递数组的指针 这点很关键
    int* left_post = postorder; int* right_post = postorder + i;
    struct TreeNode* T = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    T->val = tmp;
    T->left = buildTree(left_in, left_size, left_post, left_size);
    T->right = buildTree(right_in, right_size, right_post, right_size);
    return T;
}
