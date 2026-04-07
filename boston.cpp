#include <bits/stdc++.h>
using namespace std;

int factor(int n){
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return i;
        }
    }
    return n;
}

int digitSum(int n){
    int s = 0;
    while(n>0){
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    int n;
    cin>>n;

    int original = n;
    int x=n;
    int sum1=0,sum2=0;
    while(x>0){
        int k=x%10;
        sum1+=k;
        x=x/10;
    }

    bool hasFactor = false;
    while(n!=1){
        int a=factor(n);
        if(a != original) hasFactor = true;
        sum2 += digitSum(a);
        n=n/a;
    }

    if(hasFactor && sum1==sum2)
        cout<<1<<endl;
    else
        cout<<0<<endl;

    return 0;
}
