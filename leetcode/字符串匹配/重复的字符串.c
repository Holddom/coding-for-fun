bool repeatedSubstringPattern(char* s) {

    int len = strlen(s);
    int i;//����Ϊi���Ӵ�  ��0��ʼ
    int j;

    for (i = 1; i * 2 <= len; i++)
    {
        if (len % i == 0)
        {
            for (j = i; j < len; j++)
            {
                if (s[j] != s[j - i])
                    break;
            }
            if (j == len)return true;
        }
    }

    return false;
}