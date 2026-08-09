#include<iostream>
#include<vector>
using namespace std;
int main(){
    // size of mat 
    // m and n
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int>(n));

    // input
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    // ek modify matrix banata hoon
    vector<vector<int>> mod(m,vector<int>(n,0));
    // int mod[m][n]={0} kabhi kabhar VLA assign nahi kar paata
    // VLA= Variable Length Array
    // mat me traverse
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                // changes in mod
                // row 
                for(int k=0;k<n;k++){
                    mod[i][k]=1;
                }
                // column
                for(int k=0;k<m;k++){
                    mod[k][j]=1;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=mod[i][j];
        }
    }
    // print
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}