#include<bits/stdc++.h>
#define MAX 1000

int binarySearch(int a[], int val, int n, int *compsBinary){
    int right = n - 1;
    int left = 0;
    while (left <= right){
        int mid = (left + right)/2;
        int mid_value = a[mid];
        if (mid_value < val){
            (*compsBinary)++;
            left = mid + 1;
        } else if (mid_value > val){
            right = mid - 1;
            (*compsBinary)++;
        } else {
            (*compsBinary)++;
            return mid;
        };
    }
    ++(*compsBinary);
    return -1;
}

int OderedLinearSearch(int a[], int val, int n, int *compsLinear){
    for (int i = 0;i < n;i++){
        (*compsLinear)++;
        if (a[i] == val){
            return i;
        }
        (*compsLinear)++;
        if (a[i] > val){
            return -1;
        }
    }
    return -1;

}

int main(){
    int n;
    int a[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    int val; scanf("%d",&val);
    int compsLinear = 0, compsBinary = 0;
    int h,k;
    h = binarySearch(a,val,n,&compsBinary);
    k = OderedLinearSearch(a,val,n,&compsLinear);
    printf("stepLinear = %d\n", compsLinear);
    printf("stepBinary = %d\n", compsBinary);
    return 0;
}
