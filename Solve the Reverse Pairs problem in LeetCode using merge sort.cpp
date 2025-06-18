int mergeAndcount(int* nums, int l, int m, int r) {
    int cnt = 0 ; 
    int j = m + 1 ; 
    for (int i = l; i <= m; i++) {
        while(j <= r && nums[i] > 2ll * nums[j]) {
            ++j ; 
        }
        cnt += j - (m + 1) ; 
    }
    int n1 = m - l + 1, n2 = r - m ;
    int *x = (int *)malloc(n1 * sizeof(int)) ; 
    int *y = (int *)malloc(n2 * sizeof(int)) ; 
    for (int i = 0; i < n1; i++) {
        x[i] = nums[i + l] ; 
    }
    for (int i = 0; i < n2; i++) {
        y[i] = nums[i + m + 1] ; 
    }
    int i = 0, t = 0, id = l ; 
    while(i < n1 && t < n2) {
        if (x[i] < y[t]) {
            nums[id++] = x[i++] ; 
        }
        else {
            nums[id++] = y[t++] ; 
        }
    }
    while(i < n1) {
        nums[id++] = x[i++] ; 
    }
    while(t < n2) {
        nums[id++] = y[t++] ; 
    }
    free(x) ; free(y) ; 
    return cnt ; 
}

int mergesortAndcount(int *nums, int l, int r) {
    if (l >= r) {
        return 0 ; 
    }
    else {
        int m = (l + r) / 2 ; 
        int count = mergesortAndcount(nums, l, m) ; 
        count += mergesortAndcount(nums, m + 1, r) ; 
        count += mergeAndcount(nums, l, m, r) ; 
        return count ; 
    }
}

int reversePairs(int* nums, int numsSize) { 
    return mergesortAndcount(nums, 0, numsSize - 1) ; 
}
