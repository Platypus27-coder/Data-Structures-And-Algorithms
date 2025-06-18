int cmp(const void *a, const void *b) {
    int *x = (int *)a ; 
    int *y = (int *)b ; 
    return *x - *y ; 
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    qsort(houses, housesSize, sizeof(int), cmp) ; 
    qsort(heaters, heatersSize, sizeof(int), cmp) ; 
    int radius = 0 ; 
    for (int i = 0; i < housesSize; i++) {
        int min_radius = 1e9 ; 
        int l = 0, r = heatersSize - 1 ; 
        while(l <= r) {
            int m = (l + r) / 2 ; 
            if (heaters[m] == houses[i]) {
                min_radius = 0 ; 
                break ;
            }
            else if (heaters[m] > houses[i]) {
                min_radius = (int)fmin(min_radius, heaters[m] - houses[i]) ; 
                r = m - 1 ;
            }
            else {
                min_radius = (int)fmin(min_radius, houses[i] - heaters[m]) ; 
                l = m + 1 ; 
            }
        }
        radius = fmax(radius, min_radius) ; 
    }
    return radius ; 
}
