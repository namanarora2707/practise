#include <bits/stdc++.h>
using namespace std;
// max element in array
int main() {
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<=n-1;i++){
        cin>>array[i];
    }
    int max_element=INT_MIN;
    for(int i=0;i<=n-1;i++){
        if(array[i]>max_element){
            max_element=array[i];
        }
    }
    cout<<max_element<<endl;
    return 0;
}