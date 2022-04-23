/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//��ƽ���汾
//����һ��һά����洢����ݹ�Ľ��

typedef struct {
    int* res;
    int idx;
    int size;
} BSTIterator;
int getsize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return getsize(root->left) +
        getsize(root->right)
        + 1;
}
void inorder(int* ret, int* size, struct TreeNode* root)
{
    if (root == NULL)
        return;
    inorder(ret, size, root->left);
    ret[(*size)++] = root->val;
    inorder(ret, size, root->right);
}
int* inorderTraversal(int* size, struct TreeNode* root)
{
    *size = 0;
    int* ret = (int*)malloc(sizeof(int) * getsize(root));
    inorder(ret, size, root);
    return ret;
}
BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* terator = (BSTIterator*)malloc(sizeof(BSTIterator));
    terator->res = inorderTraversal(&(terator->size), root);
    terator->idx = 0;
    return terator;
}

int bSTIteratorNext(BSTIterator* obj) {
    return obj->res[(obj->idx)++];
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->idx < obj->size;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->res);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/