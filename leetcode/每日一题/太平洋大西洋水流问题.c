

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

static const int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
//方向二维数组用于控制dfs时搜索的方块的移动
void dfs(int row, int col, bool** ocean, int** heights, int m, int n)
{
    //dfs的具体实现
    if (ocean[row][col]) return;
    ocean[row][col] = true;  //能成功遍历到的，我们要设为ture
    for (int i = 0; i < 4; i++)  //下面看看往四个方向能不能移动
    {
        int nextrow = row + direction[i][0];
        int nextcol = col + direction[i][1];
        //下面是约束条件
        if (nextrow >= 0 && nextrow < m && nextcol >= 0 && nextcol < n && heights[nextrow][nextcol] >= heights[row][col])
        {
            dfs(nextrow, nextcol, ocean, heights, m, n);
        }
    }
}
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {

    int m = heightsSize;    //共m行
    int n = heightsColSize[0];  //每m行都有n列元素
    //下面开始创建标记数组
    //c语言用bool类型很魔幻 但确实节省了空间 比较力扣上支持嘛
    bool** pacific = (bool**)malloc(sizeof(bool*) * m);  //先建立行
    bool** atlantic = (bool**)malloc(sizeof(bool*) * m);  //先建立行
    //然后建立列
    for (int i = 0; i < m; i++)
    {
        pacific[i] = (bool*)malloc(sizeof(bool) * n);
        atlantic[i] = (bool*)malloc(sizeof(bool) * n);
        //顺便初始化
        memset(pacific[i], 0, sizeof(bool) * n);
        memset(atlantic[i], 0, sizeof(bool) * n);
    }
    //下面开始四次dfs搜索 太平洋 从行
    for (int i = 0; i < m; i++)
    {
        dfs(i, 0, pacific, heights, m, n);
    }
    //太平洋 从列
    for (int j = 1; j < n; j++)
    {
        dfs(0, j, pacific, heights, m, n); //注意到我传递的列是1 因为第0列被扫过了
    }
    //大西洋 从行
    for (int i = 0; i < m; i++)
    {
        dfs(i, n - 1, atlantic, heights, m, n);  //最后一列的每一行
    }
    //大西洋 从列
    for (int j = 0; j < n - 1; j++)  //注意我终止条件是n-1，因为n-1已经在上个循环扫过了
    {
        dfs(m - 1, j, atlantic, heights, m, n);
    }
    //malloc答案数组
    int** ret = (int**)malloc(sizeof(int*) * m * n);//共可能m*n个
    *returnColumnSizes = (int*)malloc(sizeof(int) * m * n);
    int pos = 0;
    //给答案数组每列分配空间
    for (int i = 0; i < m * n; i++)
    {
        ret[i] = (int*)malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;  //返回列值初始化
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
        free(atlantic[i]);//顺便释放内存
    }
    *returnSize = pos;
    free(pacific);
    free(atlantic);
    return ret;
}


