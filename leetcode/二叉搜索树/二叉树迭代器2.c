/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    struct TreeNode* cur;
    struct TreeNode* stk[128];
    int top;
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* ret = (BSTIterator*)malloc(sizeof(BSTIterator));
    ret->top = 0;
    ret->cur = root;
    return ret;
}

int bSTIteratorNext(BSTIterator* obj) {
    while (obj->cur != NULL)
    {
        obj->stk[obj->top++] = obj->cur;
        obj->cur = obj->cur->left;
    }
    obj->cur = obj->stk[--obj->top];
    int ret = obj->cur->val;
    obj->cur = obj->cur->right;
    return ret;

}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->cur != NULL || obj->top != 0;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/
