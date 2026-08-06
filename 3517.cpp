#include <bits/stdc++.h>
using namespace std;
string smallestPalindrome(string s) {
    // frequency nikalna
    vector<int> freq(26,0);
    int n=s.size();
    for(int i=0;i<n;i++){
        int c=s[i]-'a';
        freq[c]++;
    }
    string ans(n,' ');
    int l=0,r=n-1;
    for(int i=0;i<26;i++){
        // left and right me insert kara
        while(freq[i]>=2){
            ans[l]=char('a'+i);
            ans[r]=char('a'+i);
            l++;
            r--;
            freq[i]-=2;
        }
        // mid me insert kara
        if(freq[i]==1){
            ans[n/2]=char('a'+i);
        }
    }
    return ans; 
}
int main() {
    
    return 0;
}