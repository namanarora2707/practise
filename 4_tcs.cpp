#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> used(100, 0);

    for(int i = 0; i < n; i++) {
        long long a;
        cin >> a;

        int pos = 0;

        while(a > 0) {
            long long rem = a % k;

            if(rem > 1) {
                cout << "NO";
                return 0;
            }

            if(rem == 1) {
                if(used[pos]) {
                    cout << "NO";
                    return 0;
                }
                used[pos] = 1;
            }

            a /= k;
            pos++;
        }
    }

    cout << "YES";
}