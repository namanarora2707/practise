#include<iostream>
using namespace std;
int main(){
    // length of array
    int n;
    cin>>n;
    // elements of array
    int arr[n];
    // input liya
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dup[n];
    // number of operations
    int q;
    cin>>q;
    // jitne operations hai utne karne hai
    while(q>0){
        // value of x
        int x;
        cin>>x;
        for(int i=0;i<n;i++){
            dup[i]=arr[i]+arr[(i-x+n)%n];
        }
        for(int i=0;i<n;i++){
            arr[i]=dup[i];
        }
        q--;
    }
    // calculate the sum
    long long sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    sum=sum%1000000007;
    cout<<sum<<endl;

}