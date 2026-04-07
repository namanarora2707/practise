#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> sum(vector<int> arr1, vector<int> arr2, int N, int M)
{
    long long int total1 = 0;
    for (int i = 0; i < N; i++)
    {
        total1 = total1 * 10 + arr1[i];
    }
    long long total2 = 0;
    for (int i = 0; i < M; i++)
    {
        total2 = total2 * 10 + arr2[i];
    }
    long long totalboth = total1 + total2;
    vector<int> ans;
    while (totalboth > 0)
    {
        int m = totalboth % 10;
        ans.push_back(m);
        totalboth /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{

    int N, M;
    cin >> N >> M;
    vector<int> arr1(N, 0);
    vector<int> arr2(M, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> arr2[i];
    }

    vector<int> result = sum(arr1, arr2, N, M);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ", ";
    }
    cout << "END";

    return 0;
}