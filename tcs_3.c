#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); 
}

int main() {
    long long n;
    scanf("%lld", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    int digits[20];
    int count = 0;

    while (n > 0) {
        digits[count++] = n % 10;
        n /= 10;
    }

    qsort(digits, count, sizeof(int), compare);

    for (int i = 0; i < count; i++) {
        printf("%d", digits[i]);
    }

    return 0;
}