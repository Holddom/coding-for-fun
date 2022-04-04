

int strStr(char* haystack, char* needle) {
    int n = strlen(haystack);
    int m = strlen(needle);
    for (int i = 0; i + m <= n; i++)
    {
        bool flag = true;
        int j;
        for (j = 0; j < m; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                flag = false;
                break;
            }

        }
        if (j == m)
            return i;
    }
    return -1;
}
