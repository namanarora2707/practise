#include<iostream>
#include<vector>

using namespace std;

int f(int n, vector<int>& op){
    //base case
    if(n==1){
        op.push_back(n);
        return op.size();
    }

    //recursive case
    if(n%2 == 0){
        op.push_back(n);
        f(n/2, op);
    }else{
        op.push_back(n);
        n = (3*n+1);
        f(n, op);
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> op;

    cout<<f(n, op)<<endl;

    return 0;

}