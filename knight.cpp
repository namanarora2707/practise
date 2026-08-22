#include <bits/stdc++.h>
using namespace std;
// 8 possible ways
int xaxis[8]={1,-1,2,2,1,-1,-2,-2};
int yaxis[8]={2,2,1,-1,-2,-2,-1,1};
bool safe(int board[][15],int r,int c,int n){
    for(int i=0;i<8;i++){
        int x=r+xaxis[i];
        int y=c+yaxis[i];
        if(x>=0 and x<n and y>=0 and y<n and board[x][y]==1){
            return false;
        }
    }
    return true;
}
// recursion different distinct ways
int f(int board[][15], int cell, int k,int n){
    // base case 1
    if(k==n) return 1;
    // base case 2
    if(cell==n*n) return 0;
    // recursion ki call par
    int r=cell/n;
    int c=cell%n;
    int count=0;
    if(safe(board,r,c,n)){
        board[r][c]=1;
        count+=f(board,cell+1,k+1,n);
        board[r][c]=0;
    }
    count+=f(board,cell+1,k,n);
    return count;
}
void fprint(int board[][15],int cell,int k,int n){
    // base case 1
    if(k==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    cout<<"{"<<i<<"-"<<j<<"} ";
                }
            }
        }
        cout<<" ";
        return;
    }
    // base case 2
    if(cell==n*n) return;
    // recursion ki call par
    int r=cell/n;
    int c=cell%n;
    int count=0;
    if(safe(board,r,c,n)){
        board[r][c]=1;
        fprint(board,cell+1,k+1,n);
        board[r][c]=0;
    }
    fprint(board,cell+1,k,n);
}
int main() {
    int n;
    cin>>n;
    int board[15][15]={0};
    // valid configuration
    fprint(board,0,0,n);
    cout<<endl;
    // total ways
    cout<<f(board,0,0,n)<<endl;
    return 0;
}