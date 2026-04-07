#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int x = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        x ^= a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        x ^= b[i];
    }
    if (x == 0) {
        cout << "Tie\n";
        return;
    }
    int bit = 0;
    for (int i = 0; i < 20; ++i) {   
        if (x & (1 << i)) bit = i;
    }
    int idx = -1;
    for (int i = 0; i < n; ++i) {
        if ((a[i] ^ b[i]) & (1 << bit)) {
            idx = i;
        }
    }
    if (idx % 2 == 0) {
        cout << "Ajisai\n";
    } else {
        cout << "Mai\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
