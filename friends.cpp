#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> freq(121,0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        freq[a]++;
    }
    // 2 loop 
    long long ans=0;
    for(int x=1;x<=120;x++){
        if(freq[x]==0) continue;
        for(int y=1;y<=120;y++){
            if(freq[y]==0) continue;
            // 3 condition
            if(y<=x*0.5 +7) continue;
            if(y>x) continue;
            if(y>100 and x<100) continue;
            ans+=(long long)freq[x]*freq[y];
            if(x==y) ans-=freq[x];
        }
    }
    cout<<ans<<endl;
    return 0;
}