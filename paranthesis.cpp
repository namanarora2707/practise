void solve(string &ans, int n,int op, int cl,vector<string> &x){
        //base case
        if(ans.size()==2*n){ 
            //ans ek string vector x ke andar daal do
            x.push_back(ans);
            return;
        }

        //recursive case
        if(op<n){ 
            ans.push_back('(');
            //ans wali string mein'(' add kia aur baaki ka kaam recursion ko bol diya
            solve(ans,n,op+1,cl,x);
            ans.pop_back();
        }
        if(op>cl){
            //ans wali string mein ')' add kia aur baaki ka kaam recursion ko bol diya
            ans.push_back(')');
            solve(ans,n,op,cl+1,x);
            ans.pop_back();
        }
    }
vector<string> generateParenthesis(int n) {
    vector<string> x;
    string ans="";
    // x.clear(); 
    solve(ans,n,0,0,x); 
    //x wale vector m sare valid parenthesis push karke return krna hai vector x
    return x;
}
