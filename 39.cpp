#include <bits/stdc++.h>
using namespace std;
void f(vector<int> &candidates,int target,int total,int i,vector<int> &comb,vector<vector<int>> &ans){
    // base case 1
    if(total==target){
        ans.push_back(comb);
        return;
    }
    // base case 2
    if(total> target or i>=candidates.size()) return;
    // recursive case
    // subset and total
    // ek element ko uthao aur saare subset bana lo
    comb.push_back(candidates[i]);
    // recursion ko call kardo
    f(candidates,target,total+candidates[i],i,comb,ans);
    // element ko hatao
    comb.pop_back();
    // recursion ko call kardo
    f(candidates,target,total,i+1,comb,ans);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> comb;
    f(candidates,target,0,0,comb,ans);
    return ans;
}
int main() { 
    
    return 0;
}