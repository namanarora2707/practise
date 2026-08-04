#include <bits/stdc++.h>
using namespace std;
string reorganizeString(string s) {
    int n=s.size();
    vector<int> freq(26,0);
    int maxfreq=0;
    int maxchar=0;
    // frequency nikal rahe hai
    for(int i=0;i<n;i++){
        int c=s[i]-'a';
        freq[c]++;
    }
    // jiski sabse zyada frequency and kitni frequency hai
    for(int i=0;i<26;i++){
        if(freq[i]>maxfreq){
            maxfreq=freq[i];
            maxchar=i;
        }
    }
    // condition
    if(maxfreq>(n+1)/2) return "";
    int i=0;
    // maxfreq ko insert karo even index
    string ans(n,' ');
    while(freq[maxchar]>0){
        ans[i]=char(maxchar+'a');
        freq[maxchar]--;
        i+=2;
    }
    // bachge huye saare alphabets ko insert karo
    for(int j=0;j<26;j++){
        while(freq[j]>0){
            if(i>=n) i=1;
            ans[i]=char(j+'a');
            i+=2;
            freq[j]--;
        }
    }
    return ans;

}

int main() {
    
    return 0;
}