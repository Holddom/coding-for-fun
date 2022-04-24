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
    //���Ƚ����Զ�����λ��ʾ
    int bit[32];
    int count = gitbit(bit, n);   //�õ���һ�鵹�������λ
    //�������
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
