int jump(int* nums, int numsSize) {
    int l = 0, r = 0; 
    int max = 0; 
    int cnt = 0; 
    while(r < numsSize - 1) {
        for (int i = l; i <= r; i++) {
            max = (int)fmax(max, i + nums[i]); 
        }
        ++cnt; 
        l = r + 1; 
        r = max; 
    }
    return cnt; 
}
