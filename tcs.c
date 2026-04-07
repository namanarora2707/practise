#include <stdio.h>
#include <string.h>

int main() {
    char s[105];
    scanf("%s", s);

    int n = strlen(s);
    if (s[0] == '0') {
        printf("0");
        return 0;
    }

    int dp[105] = {0};

    dp[0] = 1;   
    dp[1] = 1;   

    for (int i = 2; i <= n; i++) {
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];

        int t = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (t >= 10 && t <= 26)
            dp[i] += dp[i - 2];
    }

    printf("%d", dp[n]);

    return 0;
}
