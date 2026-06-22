#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int maxProduct(int n) {
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        int maximum = 0;

        for (int j = 1; j < i; j++) {
            maximum = max(maximum,
                          max(j * (i - j), j * dp[i - j]));
        }

        dp[i] = maximum;
    }

    return dp[n];
}
int main() {
    int n;
    printf("Enter rope length: ");
    scanf("%d", &n);
    printf("Max Product = %d\n", maxProduct(n));
    return 0;
}
