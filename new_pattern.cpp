#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long k=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<pow(k,k)<<" \t";
            k++;
        }
        cout<<endl;
    }
    return 0;
}