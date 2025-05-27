int maxArea(int* height, int heightSize) {
    int l = 0, r = heightSize - 1; 
    int max_amount = 0 ; 
    while(l < r) {
        if (height[l] < height[r]) {
            if (height[l] * (r - l) > max_amount) {
                max_amount = height[l] * (r - l) ; 
            }
            ++l ; 
        }
        else if (height[l] > height[r]) {
            if (height[r] * (r - l) > max_amount) {
                max_amount = height[r] * (r - l) ; 
            }
            --r ; 
        }
        else {
            if (height[r] * (r - l) > max_amount) {
                max_amount = height[r] * (r - l) ; 
            }
            ++l; --r ; 
        }
    }
    return max_amount ; 
}
