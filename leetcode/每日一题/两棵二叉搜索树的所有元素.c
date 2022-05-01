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
void inorder(struct TreeNode *node, int *res, int *pos) {
    if (node) {
        inorder(node->left, res, pos);
        res[(*pos)++] = node->val;
        inorder(node->right, res, pos);
    }
}
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int val1[5001];   int count1=0;
    int val2[5001];   int count2=0;
    //�ֱ�������
      inorder(root1,val1,&count1);  //�õ�������������
      inorder(root2,val2,&count2);
    //��������ϳ�һ����������
    int *ret=(int *)malloc(sizeof(int)*(count1+count2));
    int i=0; int j=0;
   *returnSize=0;
    //����һ����Ϊ��
    if(count1==0)
    {
        for(j=0;j<count2;j++)
        {
            ret[j]=val2[j];
        }
        *returnSize=count2;
        return ret;
    }
    if(count2==0)
    {
        for(i=0;i<count1;i++)
        {
            ret[i]=val1[i];
        }
        *returnSize=count1;
        return ret;
    }
    //���ö���Ϊ��
    while(i<count1&&j<count2)
    {
        if(val1[i]<=val2[j])
        {
            ret[(*returnSize)++]=val1[i];
            i++;
        }
        else
        {
            ret[(*returnSize)++]=val2[j];
            j++;
        }
    }
    if(i==count1) //�����һ�����ȱ�����
    {
        while(j<count2)  
        {
            ret[(*returnSize)++]=val2[j];
            j++;
        }
    }
    if(j==count2){
            while(i<count1)
            {
                ret[(*returnSize)++]=val1[i];
                i++;
            }
    }
    return ret;
}

