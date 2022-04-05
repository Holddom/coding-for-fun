bool repeatedSubstringPattern(char* s) {

    int len = strlen(s);
    int i;//长度为i的子串  从0开始
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