#include <bits/stdc++.h>
using namespace std;
// leetcode
void f(vector<int> &nums,int i,vector<vector<int>> &ans, vector<int> subset){
    // base case 
    if(i==nums.size()){
        ans.push_back(subset);
        return;
    }
    // recursive case
    // ek element ko utha aur saare subset bana de
    subset.push_back(nums[i]);
    // recursion ko bolna saare subset nikal kar de
    f(nums,i+1,ans,subset); // saare subset nikal kar dedega
    // ab element ko hata ke banao saare subset
    subset.pop_back();
    // saare subset bana ke de
    f(nums,i+1,ans,subset);

}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> subset;
    f(nums,0,ans,subset);
    return ans;
}

// array
void farray(int nums[],int n,int i,int ans[][100],int &anssize,int subset[],int subsetsize){
    // base case
    if(i==n){
        for(int j=0;j<subsetsize;j++){
            ans[anssize][j]=subset[j];
        }
        anssize++;
        return;
    }
    // recursive case
    subset[subsetsize]=nums[i];
    farray(nums,n,i+1,ans,anssize,subset,subsetsize+1);
    farray(nums,n,i+1,ans,anssize,subset,subsetsize);

}
int main() {
    int nums[]={1,2,3};
    int n=3;
    int ans[100][100];
    int subset[100];
    int anssize=0;
    farray(nums,n,0,ans,anssize,subset,0);
    for(int i=0;i<8;i++){
        cout<<"{ ";
        for(int j=0;j<5;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}