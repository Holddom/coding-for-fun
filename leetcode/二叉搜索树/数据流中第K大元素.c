struct Tree {
    struct Tree* left;      //c���ԵĿ����Ƕ�׽ṹ��
    struct Tree* right;     //ʮ�ֵ��鷳
    int count;
    int val;
};
typedef struct {
    struct Tree* Tree;
} KthLargest;
struct Tree* createTree(struct Tree* obj, int val)//��������������
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
    if (obj->val >= val)  //һ��Ҫ��һ�����ںţ�����Ӿ��ڲ����Ԫ�ؿ��Ը�ԭ�������ֵ���
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
//�ҵ���k�����Ԫ��
int find(struct Tree* obj, int k)
{
    int sum = 1;
    if (obj->right != NULL)
    {
        sum += obj->right->count;  //�ýڵ�������������Ľڵ�
    }
    if (k == sum)  return obj->val;
    if (k < sum) return find(obj->right, k);  //��������Ŀ��
    else {
        return find(obj->left, k - sum);   //��������Ŀ�꣬�ݹ��kֵ��Ҫ��ȥ���ڵ���������ĸ���
    }
}
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));//�սڵ�
    obj->Tree = malloc(sizeof(struct Tree));
    obj->Tree->left = NULL;    //ע����ʹ��������ָ��
    obj->Tree->right = NULL;
    obj->Tree->val = 0;
    obj->Tree->count = k;  //����countֵ��Ϊk���ͼ�¼��kֵ
    for (int i = 0; i < numsSize; i++)    //ע���ҵĴ���
    {
        obj->Tree->left = createTree(obj->Tree->left, nums[i]); //�ѿսڵ����������Ϊ����ָ��
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
    //��free��������������
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
