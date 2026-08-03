#include <bits/stdc++.h>
using namespace std;
void f(string &s, int i,vector<vector<string>> &ans, vector<string> par){
    // base case
    int n=s.size();
    if(i==n){
        ans.push_back(par);
    }
    else{
        for(int j=i;j<n;j++){
            if(ispalindrome(s,i,j)){
                par.push_back(s.substr(i,j-i+1));
                // recursion ko call kkardunga
                f(s,j+1,ans,par);
                par.pop_back();
            }
        }
    }
}
bool ispalindrome(string &s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}
vector<vector<string>> partition(string s) {
    vector<string> par;
    vector<vector<string>> ans;
    f(s,0,ans,par);
    return ans;

}
int main() {
    
    return 0;
}