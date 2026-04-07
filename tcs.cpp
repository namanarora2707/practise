#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == '0') {
        cout << 0;
        return 0;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;  
    for (int i = 2; i <= n; i++) {
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];

        int t = stoi(s.substr(i - 2, 2));
        if (t >= 10 && t <= 26)
            dp[i] += dp[i - 2];
    }

    cout << dp[n];

    return 0;
}
