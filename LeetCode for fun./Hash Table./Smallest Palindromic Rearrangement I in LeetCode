char* smallestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 1 || n == 2) {
        return s; 
    }
    int hash[256] = {0}; 
    for (int i = 0; i < n / 2; i++) {
        hash[s[i]]++; 
    }
    for (int i = 0, j = 0; i < 256, j < n / 2; i++) {
        while(hash[i]--) {
            s[j] = i; 
            s[n - j - 1] = i;  
            ++j; 
        }
    }
    return s; 
}
