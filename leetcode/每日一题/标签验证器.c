#define MIN(a, b) ((a) < (b) ? (a) : (b))

bool isValid(char * code){
    int n = strlen(code);
    char ** tags = (char **)malloc(sizeof(char *) * n);

    int i = 0;
    int top = 0;
    while (i < n) {
        if (code[i] == '<') {
            if (i == n - 1) {
                return false;
            }
            if (code[i + 1] == '/') {
                char *p = strchr(code + i, '>');
                if (NULL == p) {
                    return false;
                }
                int j = p - code;
                if (top == 0 || strncmp(tags[top - 1], code + i + 2, j - (i + 2)) != 0) {
                    return false;
                }
                free(tags[top - 1]);
                top--;
                i = j + 1;
                if (top == 0 && i != n) {
                    return false;
                }
            } else if (code[i + 1] == '!') {
                if (top == 0) {
                    return false;
                }
                if (strncmp(code + i + 2, "[CDATA[", 7) != 0) {
                    return false;
                }
                char *p = strstr(code + i, "]]>");
                if (NULL == p) {
                    return false;
                }
                int j = p - code;
                i = j + 1;
            } else {
                char *p = strchr(code + i, '>');
                if (NULL == p) {
                    return false;
                }
                int j = p - code;
                int len = MIN(n - i - 1, j - (i + 1));
                if (len < 1 || len > 9) {
                    return false;
                }
                for (int k = 0; k < len; k++) {
                    if (!isupper(code[i + 1 + k])) {
                        return false;
                    }
                }
                char *tagname = (char *)malloc(sizeof(char) * (len + 1));
                strncpy(tagname, code + i + 1, len);
                tagname[len] = 0;
                tags[top++] = tagname;
                i = j + 1;
            }
        } else {
            if (top == 0) {
                return false;
            }
            ++i;
        }
    }
    return top == 0;
}



