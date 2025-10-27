/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int char_to_int(char c) {
    if (c == 'A') 
        return 0; 
    if (c == 'C') 
        return 1; 
    if (c == 'G')
        return 2; 
    return 3; 
}

char** findRepeatedDnaSequences(char* s, int* returnSize) {
    *returnSize = 0; 
    if (strlen(s) < 10) 
        return NULL; 
    int hash[1048576] = {0}; 
    char **res = (char **)malloc(1000 * sizeof(char *)) ; 
    int index = 0; 
    long long code = 0; 
    for (int i = 0; i < 10; i++) {
        code += 1ll * char_to_int(s[i]) * (long long)pow(4, 10 - i - 1) ; 
    }
    hash[code] = 1 ; 
    for (int i = 1; i <= strlen(s) - 10; i++) {
        code = 0; 
        int cnt = 1; 
        for (int j = i; j < i + 10; j++) {
            code += 1ll * char_to_int(s[j]) * (long long)pow(4, 10 - cnt) ; 
            ++cnt ; 
        }
        if (hash[code] == 1) {
            res[index] = (char *)malloc(11 * sizeof(char));
            strncpy(res[index], s + i, 10);
            res[index][10] = '\0';
            ++index;
        }
        hash[code]++ ; 
    }   
    *returnSize = index ; 
    return res;
}
