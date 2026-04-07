#include <bits/stdc++.h>
using namespace std;

int main() {
    //Creation of array
    int array[5];
    int array_b[]={1,3,2,4,5};

    //size of operator
    int n=sizeof(array_b)/sizeof(int);
    cout<<n<<endl;

    // array read
    for(int i=0;i<=n-1;i++){
        cout<<array_b[i]<<" ";
    }
    cout<<endl;

    //user input for array
    int size;
    cin>>size;
    int array_c[size];
    for(int i=0;i<=size-1;i++){
        cin>>array_c[i];
    }
    for(int i=0;i<=size-1;i++){
        cout<<array_c[i]<<" ";
    }

    // update
    array_b[2]+=10;
    cout<<array_b[2]<<endl;
    return 0;
}