#include <iostream>
#include<string>
#include <algorithm>
using namespace std;
bool palindrome(string s){
    int i=0;
    int j=s.size()-1;
    
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
string smallestPalindrome(string s){
    sort(s.begin(),s.end());
    
    
     do {
        if(palindrome(s)){
            return s;
        }
    } while(next_permutation(s.begin(), s.end())); 
    return "";
}
int main(){
    string s="babab";
    
}