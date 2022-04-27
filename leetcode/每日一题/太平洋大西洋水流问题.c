

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

static const int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
//�����ά�������ڿ���dfsʱ�����ķ�����ƶ�
void dfs(int row, int col, bool** ocean, int** heights, int m, int n)
{
    //dfs�ľ���ʵ��
    if (ocean[row][col]) return;
    ocean[row][col] = true;  //�ܳɹ��������ģ�����Ҫ��Ϊture
    for (int i = 0; i < 4; i++)  //���濴�����ĸ������ܲ����ƶ�
    {
        int nextrow = row + direction[i][0];
        int nextcol = col + direction[i][1];
        //������Լ������
        if (nextrow >= 0 && nextrow < m && nextcol >= 0 && nextcol < n && heights[nextrow][nextcol] >= heights[row][col])
        {
            dfs(nextrow, nextcol, ocean, heights, m, n);
        }
    }
}
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {

    int m = heightsSize;    //��m��
    int n = heightsColSize[0];  //ÿm�ж���n��Ԫ��
    //���濪ʼ�����������
    //c������bool���ͺ�ħ�� ��ȷʵ��ʡ�˿ռ� �Ƚ�������֧����
    bool** pacific = (bool**)malloc(sizeof(bool*) * m);  //�Ƚ�����
    bool** atlantic = (bool**)malloc(sizeof(bool*) * m);  //�Ƚ�����
    //Ȼ������
    for (int i = 0; i < m; i++)
    {
        pacific[i] = (bool*)malloc(sizeof(bool) * n);
        atlantic[i] = (bool*)malloc(sizeof(bool) * n);
        //˳���ʼ��
        memset(pacific[i], 0, sizeof(bool) * n);
        memset(atlantic[i], 0, sizeof(bool) * n);
    }
    //���濪ʼ�Ĵ�dfs���� ̫ƽ�� ����
    for (int i = 0; i < m; i++)
    {
        dfs(i, 0, pacific, heights, m, n);
    }
    //̫ƽ�� ����
    for (int j = 1; j < n; j++)
    {
        dfs(0, j, pacific, heights, m, n); //ע�⵽�Ҵ��ݵ�����1 ��Ϊ��0�б�ɨ����
    }
    //������ ����
    for (int i = 0; i < m; i++)
    {
        dfs(i, n - 1, atlantic, heights, m, n);  //���һ�е�ÿһ��
    }
    //������ ����
    for (int j = 0; j < n - 1; j++)  //ע������ֹ������n-1����Ϊn-1�Ѿ����ϸ�ѭ��ɨ����
    {
        dfs(m - 1, j, atlantic, heights, m, n);
    }
    //malloc������
    int** ret = (int**)malloc(sizeof(int*) * m * n);//������m*n��
    *returnColumnSizes = (int*)malloc(sizeof(int) * m * n);
    int pos = 0;
    //��������ÿ�з���ռ�
    for (int i = 0; i < m * n; i++)
    {
        ret[i] = (int*)malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;  //������ֵ��ʼ��
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pacific[i][j] && atlantic[i][j])
            {
                ret[pos][0] = i;
                ret[pos][1] = j;
                pos++;
            }
        }
        free(pacific[i]);
        free(atlantic[i]);//˳���ͷ��ڴ�
    }
    *returnSize = pos;
    free(pacific);
    free(atlantic);
    return ret;
}


