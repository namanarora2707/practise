#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<pair<long long, int>> prefix;
    prefix.push_back({0, -1});
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        prefix.push_back({sum, i});
    }
    sort(prefix.begin(), prefix.end());
    int maxLen = 0;
    for (int i = 0; i < prefix.size();) {
        int j = i;
        while (j < prefix.size() && prefix[j].first == prefix[i].first) {
            j++;
        }
        int minIndex = prefix[i].second;
        int maxIndex = prefix[j - 1].second;
        maxLen = max(maxLen, maxIndex - minIndex);
        i = j;
    }
    cout << maxLen << endl;
    return 0;
}
