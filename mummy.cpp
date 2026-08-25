#include<iostream>
using namespace std;
int main(){
    // size
    int n;
    cin>>n;
    // square matrix
    int mat[100][100];
    // input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    // check lower triangular
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(mat[i][j]!=0){
                cout<<"false";
                return 0;
            }
        }
    }
    cout<<"true"<<endl;
    return 0;
}