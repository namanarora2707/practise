#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    int g=2;
    for(int m=n;m>0;m/=2){
        for(int i=1;i<=n-m;i++){
            cout<<" ";
        }
        for(int cnt=1;cnt<=m;){
            if(prime(g)){
                cout<<g<<" ";
                cnt++;
            }
            g++;
        }
        cout<<endl;
    }
    return 0;
}