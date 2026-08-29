#include<iostream>
using namespace std;
int main(){
    // input
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    char park[n][m];
    // input
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>park[i][j];
        }
    }
    // traverse
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // blockade
            if(park[i][j]=='#'){
                break;
            }
            //  dot occur hua
            if(park[i][j]=='.'){
                s-=2;
            }
            // star occur hua 
            else if(park[i][j]=='*'){
                s+=5;
            }
            if(s<=k){
                cout<<"No";
                return 0;
            }
            if(j<m-1){
                s--;
            }
        }
    }
    cout<<"Yes"<<endl;
    cout<<s;
    return 0;
}