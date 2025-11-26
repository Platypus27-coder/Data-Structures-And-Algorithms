// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1 ; 
    while(l <= r) {
        int m = (l + r) / 2 ; 
        if (nums[m] == target) {
            return m ;
        }
        if (nums[l] <= nums[m]) {
            if (target >= nums[l] && target < nums[m]) {
                r = m - 1 ; 
            }
            else {
                l = m + 1 ; 
            }
        }
        else {
            if (nums[m] < target && target <= nums[r]) {
                l = m + 1 ; 
            }
            else {
                r = m - 1 ; 
            }
        }
    }
    return -1 ; 
}
