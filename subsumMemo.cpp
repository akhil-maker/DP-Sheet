#include<iostream>
#include<vector>
using namespace std;
bool f(int a[], int n, int ind, int t, vector<vector<int>>& dp){
    if(t==0) return true;
    if(ind==0) return (a[ind]==t);
    if(dp[ind][t]!=-1) return dp[ind][t];
    bool take = (a[ind]<=t)?f(a, n, ind-1, t-a[ind], dp):false;
    bool nottake = f(a, n, ind-1, t, dp);
    return dp[ind][t] = take || nottake;
}
int main(){
    int n, t;
    cin>>n>>t;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    vector<vector<int>> dp(n, vector<int>(t+1, -1));
    cout<<f(a, n, n-1, t, dp);
}