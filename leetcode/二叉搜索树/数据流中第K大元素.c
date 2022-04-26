struct Tree {
    struct Tree* left;      //c语言的苦就是嵌套结构体
    struct Tree* right;     //十分的麻烦
    int count;
    int val;
};
typedef struct {
    struct Tree* Tree;
} KthLargest;
struct Tree* createTree(struct Tree* obj, int val)//建立二叉搜索树
{
    if (obj == NULL)
    {
        obj = (struct Tree*)malloc(sizeof(struct Tree));
        obj->count = 1;
        obj->val = val;
        obj->left = NULL;
        obj->right = NULL;
        return obj;
    }
    if (obj->val >= val)  //一定要加一个等于号，这题坑就在插入的元素可以根原来树里的值相等
    {
        obj->count += 1;
        obj->left = createTree(obj->left, val);
    }
    if (obj->val < val)
    {
        obj->count += 1;
        obj->right = createTree(obj->right, val);
    }
    return obj;
}
//找到第k个大的元素
int find(struct Tree* obj, int k)
{
    int sum = 1;
    if (obj->right != NULL)
    {
        sum += obj->right->count;  //该节点加上其右子树的节点
    }
    if (k == sum)  return obj->val;
    if (k < sum) return find(obj->right, k);  //右子树有目标
    else {
        return find(obj->left, k - sum);   //左子树有目标，递归的k值需要减去根节点加右子树的个数
    }
}
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));//空节点
    obj->Tree = malloc(sizeof(struct Tree));
    obj->Tree->left = NULL;    //注意我使用了两次指针
    obj->Tree->right = NULL;
    obj->Tree->val = 0;
    obj->Tree->count = k;  //它的count值设为k，就记录了k值
    for (int i = 0; i < numsSize; i++)    //注意我的传参
    {
        obj->Tree->left = createTree(obj->Tree->left, nums[i]); //把空节点的左子树作为建树指针
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    obj->Tree->left = createTree(obj->Tree->left, val);
    return find(obj->Tree->left, obj->Tree->count);
}

void freetree(struct Tree* root)
{
    if (root->left != NULL)
        freetree(root->left);
    if (root->right != NULL)
        freetree(root->right);
    free(root);
}
void kthLargestFree(KthLargest* obj) {
    //先free掉建立的搜索树
    freetree(obj->Tree->left);
    free(obj->Tree);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/
