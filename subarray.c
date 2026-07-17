#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("All Subarrays are:\n");

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            printf("{ ");
            for (int k = i; k <= j; k++) {
                printf("%d ", arr[k]);
            }
            printf("}\n");
        }
    }

    return 0;
}