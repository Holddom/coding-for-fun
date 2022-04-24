int gitbit(int* bit, int n)
{
    int count = 0;
    while (n != 0)
    {
        bit[count++] = n % 2;
        n /= 2;
    }
    bit[count] = '\0';
    return count;
}
int binaryGap(int n) {
    //首先将数以二进制位表示
    int bit[32];
    int count = gitbit(bit, n);   //得到了一组倒序二进制位
    //找最长距离
    int maxlen = 0;
    for (int i = count - 1; i >= 0; i--)
    {
        if (bit[i] == 1)
        {
            int j = i - 1;
            while (j >= 0 && bit[j] != 1)
            {
                j--;
            }
            if (j < 0)
                continue;
            if (bit[j] == 1)
                maxlen = (i - j > maxlen) ? (i - j) : maxlen;
        }
    }
    return maxlen;
}
