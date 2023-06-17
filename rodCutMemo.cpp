#include<iostream>
#include<vector>
using namespace std;
int f(int ind, int t, int a[], vector<vector<int>>& dp){
    if(t==0) return 0;
    if(ind==0) return t*a[ind];
    if(dp[ind][t]!=-1) return dp[ind][t];
    int nottake = f(ind-1, t, a, dp);
    int rodlen = ind+1, take = 0;
    if(rodlen<=t) take = a[ind] + f(ind, t-rodlen, a, dp);
    return dp[ind][t] = max(take, nottake);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    cout<<f(n-1, n, a, dp);
}