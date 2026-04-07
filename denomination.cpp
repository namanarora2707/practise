#include <bits/stdc++.h>
using namespace std;
bool f(vector<int>& denominations,int amount,int n){
    if(amount==0) return true;
    if(n==0) return false;
    if(denominations[n-1]<=amount){
        return f(denominations,amount-denominations[n-1],n)||f(denominations,amount,n-1);
    }
    else{
        return f(denominations,amount,n-1);
    }
}
int f1(vector<int>& denominations,int amount,int n){
    if(amount==0) return 1;
    if(n==0) return 0;
    if(denominations[n-1]<=amount){
        return f1(denominations,amount-denominations[n-1],n)+f1(denominations,amount,n-1);
    }
    else{
        return f1(denominations,amount,n-1);
    }
}
int main() {

    vector<int> denominations = {2,7,10};
    int amount;
    cin >> amount;
    int n = denominations.size();
    if(f(denominations,amount,n)){
        cout << "Possible to form the amount with given denominations\n";
    }
    else{
        cout << "Not possible to form the amount with given denominations\n";
    }
    return 0;
}