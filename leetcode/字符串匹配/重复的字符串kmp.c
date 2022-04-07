void next(int* match, char* s)
{
    int len = strlen(s);
    match[0] = -1;
    int i;
    int j;
    for (j = 1; j < len; j++) {
        i = match[j - 1];
        while ((i >= 0) && (s[i + 1] != s[j]))
            i = match[i];
        if (s[i + 1] == s[j])
            match[j] = i + 1;
        else match[j] = -1;
    }

}
int kmp(char* k, char* s)
{
    int n = strlen(k);
    int m = strlen(s);
    int* match = (int*)malloc((m) * sizeof(int));
    next(match, s);
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (k[i] == s[j]) {
            i++; j++;
        }
        else if (j > 0)
            j = match[j - 1] + 1;
        else
            i++;
    }
    //free(match);
    return (j == m) ? i - m : -1;
}
bool repeatedSubstringPattern(char* s) {
    //kmp°æ
    int len = strlen(s);
    char* k = (char*)malloc((2 * len + 1) * sizeof(char));
    k[0] = '\0';
    strcat(k, s);
    strcat(k, s);
    k[2 * len - 1] = '\0';
    int flag = kmp(k + 1, s);
    free(k);
    return flag != -1;
}